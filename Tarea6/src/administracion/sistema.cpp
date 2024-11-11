#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <unistd.h> // Para usar usleep()
#include "sistema.hpp"

using namespace std;

// Configuración inicial y variables compartidas 
const int BUFFER_SIZE = 10;
queue<pair<int, chrono::steady_clock::time_point>> buffer;
mutex mtx;      // protege el acceso al bufer compartido
condition_variable cv_client, cv_operator;  // notifica a clientes y operadores
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE), full_slots(0);
mutex stats_mtx; // mutex para proteger el acceso a estadísticas
vector<double> tiempos_espera;
vector<double> tiempos_procesamiento; 

// variable para controlar el sistema
bool sistema_activo = true; 

// Función para los clientes (productores)
void cliente(int id) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(100, 1000);
    
    while (sistema_activo) {      // El sistema siempre está activo
        int solicitud = id * 100 + rand() % 100; // Genera una solicitud única
        empty_slots.acquire(); // Espera hasta que haya espacio en el búfer

        // A continuuación se entra a la "sección crítica" para asegurar que solo un operador acceda al búfer a la vez,
        {
            unique_lock<mutex> lock(mtx);  // se protege con mutex para que solo haya un cliente(hilo) a la vez
            buffer.push({solicitud, chrono::steady_clock::now()}); // se añade el steady clock now para guardar el tiempo actual
            //cout << "Cliente " << id << " ha añadido solicitud " << solicitud << "\n";
        }

        full_slots.release();       // notifica que hay una solicitud disponible
        cv_operator.notify_one();   // notifica a los operadores
        this_thread::sleep_for(chrono::milliseconds(distribution(generator))); // Pausa aleatoria
    }
}

// Función para los operadores (consumidores)
void operador(int id) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(500, 1500);

    while (sistema_activo) {      // El sistema siempre está activo
        full_slots.acquire(); // Espera hasta que haya solicitudes en el búfer

        int solicitud;        // Se instancia la variable solicitud
        chrono::steady_clock::time_point inicio, fin;    // se definen variables para el inicio y el fin del proceso
        pair<int, chrono::steady_clock::time_point> item; // almacenará el par ordenado (solicitud, tiempo de creación) extraído del buffer
        
        {
            unique_lock<mutex> lock(mtx);    // se protege el acceso con un mutex
            cv_operator.wait(lock, [] {return !buffer.empty(); });   // espera que el bufer no esté vacío
            item = buffer.front();           // se extrea la info del buffer en int
            solicitud = item.first;         // se extrae la solicitud    
            inicio = item.second;           // se extrae el tiempo de inicio de la creación
            buffer.pop();                   // se extrae la solicitud mas antigua del buffer
            //cout << "Operador " << id << " está procesando solicitud " << solicitud << "\n";
        }
        // Calcula el tiempo de espera de la solicitud en el buffer
        fin = chrono::steady_clock::now();  // se extrae el tiempo donde se finalizó el proceso
        chrono::duration<double> wait_time = fin - inicio;
        /*
        se inicia otro bloque para lock, donde se asegura que varios hilos no puedan accesar al mismo tiempo 
        a los vectores tiempos_espera y tiempos_procesamiento utilizados en la función para monitoreo       
        */
        {
            lock_guard<mutex> stats_lock(stats_mtx);        // se protege con otro mutex
            tiempos_espera.push_back(wait_time.count());    // se añade el tiempo de espera al vector de tiempos de espera total
        }
        
        cv_client.notify_one(); // Notifica a un cliente que hay espacio en el búfer
        
        
        // se simula el tiempo de procesamiento
        chrono::steady_clock::time_point inicio_proceso = chrono::steady_clock::now();
        this_thread::sleep_for(chrono::milliseconds(distribution(generator))); // Simula el tiempo de procesamiento
        chrono::steady_clock::time_point fin_proceso = chrono::steady_clock::now();
        
        // se calcula y guarda el tiempo de procesamiento

        chrono::duration<double> process_time = fin_proceso - inicio_proceso;

        {       // se protege ante condiciones de carrera
            lock_guard<mutex> stats_lock(stats_mtx);
            tiempos_procesamiento.push_back(process_time.count());      // se actualiza el vector de tiempos de procesamientos totales
        }
        empty_slots.release();
    }
}



double calcular_uso_cpu() {
    std::ifstream stat_file("/proc/stat");
    std::string line;
    long user, nice, system, idle, iowait, irq, softirq, steal;
    long prev_total = 0, prev_idle = 0;

    if (stat_file.is_open()) {
        // Leer la primera línea de /proc/stat
        std::getline(stat_file, line);
        sscanf(line.c_str(), "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        
        prev_idle = idle + iowait;
        prev_total = user + nice + system + idle + iowait + irq + softirq + steal;
        stat_file.close();
    }

    // Esperar 100 milisegundos antes de la segunda lectura
    usleep(100000);

    // Segunda lectura del archivo
    stat_file.open("/proc/stat");
    long user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2;
    long total = 0, idle_total = 0;

    if (stat_file.is_open()) {
        std::getline(stat_file, line);
        sscanf(line.c_str(), "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
               &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2, &steal2);

        idle_total = idle2 + iowait2;
        total = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2 + steal2;
        stat_file.close();
    }

    // Cálculo de diferencia entre las dos lecturas
    double total_dif = total - prev_total;
    double idle_dif = idle_total - prev_idle;

    // Calcular el porcentaje de uso de CPU
    double cpu_usage = (total_dif - idle_dif) / total_dif * 100.0;
    return cpu_usage;
}

void mostrar_metricas() {

    int iteraciones = 3;
    for (int i = 0; i < iteraciones; ++i) {
    
        this_thread::sleep_for(chrono::seconds(10));      // mostrar cada 5 segundos

        double total_espera = 0;
        double total_procesamiento = 0;
        int num_esperas = 0;
        int num_procesamientos = 0;
        double promedio_espera = 0;
        double promedio_procesamiento = 0;


        {   // se evitan condiciones de carrera
            lock_guard<mutex> stats_lock(stats_mtx);

            // se usan operadores para los bucles en una sola línea y mantener el orden
            for (double t : tiempos_espera) total_espera += t;
            for (double t: tiempos_procesamiento) total_procesamiento += t;
            num_esperas = tiempos_espera.size();
            num_procesamientos = tiempos_procesamiento.size();
        }

        // calcula el promedio de tiempo de espera y procesamiento
        // se usan operadores para los condicionales en una sola línea y mantener el orden
        promedio_espera = num_esperas > 0 ? total_espera / num_esperas : 0;
        promedio_procesamiento = num_procesamientos > 0 ? total_procesamiento / num_procesamientos : 0;

        // se llama a la función de uso de CPU
        double cpu_usage = calcular_uso_cpu();

        // Imprimir resultados
        cout << "\n--- MÉTRICAS DE RENDIMIENTO ---\n";
        cout << "Promedio de tiempo de espera en búfer: " << promedio_espera << " segundos\n";
        cout << "Promedio de tiempo de procesamiento: " << promedio_procesamiento << " segundos\n";
        cout << "Uso de CPU: " << cpu_usage << "%\n";
        cout << "--------------------------------\n";
    }
    sistema_activo = false;
    cv_client.notify_all();
    cv_operator.notify_all();
}
