#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <random>
#include "sistema.hpp"

using namespace std;

// Configuración inicial y variables compartidas 
const int BUFFER_SIZE = 10;
queue<pair<int, chrono::steady_clock::time_point>> buffer;
mutex mtx;
condition_variable cv_client, cv_operator;
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE), full_slots(0);
mutex stats_mtx; // mutex para proteger el acceso a estadísticas
vector<double> tiempos_espera;
vector<double> tiempos_procesamiento; 

// Función para los clientes (productores)
void cliente(int id) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(100, 1000);
    
    while (true) {      // El sistema siempre está activo
        int solicitud = id * 100 + rand() % 100; // Genera una solicitud única
        empty_slots.acquire(); // Espera hasta que haya espacio en el búfer

        // A continuuación se entra a la "sección crítica" para asegurar que solo un operador acceda al búfer a la vez,
        {
            lock_guard<mutex> lock(mtx);  // se protege con mutex para que solo haya un cliente(hilo) a la vez
            buffer.push({solicitud, chrono::steady_clock::now()}); // se añade el steady clock now para guardar el tiempo actual
            cout << "Cliente " << id << " ha añadido solicitud " << solicitud << "\n";
        }

        cv_operator.notify_one(); // Notifica a un operador
        this_thread::sleep_for(chrono::milliseconds(distribution(generator))); // Pausa aleatoria
    }
}

// Función para los operadores (consumidores)
void operador(int id) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(500, 1500);

    while (true) {      // El sistema siempre está activo
        full_slots.acquire(); // Espera hasta que haya solicitudes en el búfer

        int solicitud;        // Se instancia la variable solicitud
        chrono::steady_clock::time_point inicio, fin;    // se definen variables para el inicio y el fin del proceso
        pair<int, chrono::steady_clock::time_point> item; // almacenará el par ordenado (solicitud, tiempo de creación) extraído del buffer
        
        {
            lock_guard<mutex> lock(mtx);    // se protege el acceso con un mutex
            item = buffer.front();           // se extrea la info del buffer en int
            solicitud = item.first;         // se extrae la solicitud    
            inicio = item.second;           // se extrae el tiempo de inicio de la creación
            buffer.pop();                   // se extrae la solicitud mas antigua del buffer
            cout << "Operador " << id << " está procesando solicitud " << solicitud << "\n";
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
        
        cv_client.notify_one(); // Notifica que hay espacio en el búfer
        this_thread::sleep_for(chrono::milliseconds(distribution(generator))); // Simula el tiempo de procesamiento
        
        // se declaaran las variables para llevar el tiempo del proceso
        chrono::steady_clock::time_point inicio_proceso = chrono::steady_clock::now();
        chrono::steady_clock::time_point fin_proceso = chrono::steady_clock::now();

        chrono::duration<double> process_time = fin_proceso - inicio_proceso;

        {       // se protege ante condiciones de carrera
            lock_guard<mutex> stats_lock(stats_mtx);
            tiempos_procesamiento.push_back(process_time.count());      // se actualiza el vector de tiempos de procesamientos totales
        }
    }
}

void mostrar_metricas() {

    while(true){
        this_thread::sleep_for(chrono::seconds(5));      // mostrar cada 5 segundos

        double total_espera = 0;
        double total_procesamiento = 0;
        int num_esperas = 0;
        int num_procesamientos = = 0;
        double promedio_espera = 0;
        double promedio_procesamiento = 0;


        {   // se evitan condiciones de carrera
            lock_guard<mutex> stats_lock(stats_mtx);

            // se usan operadores para los bucles en una sola línea y mantener el orden
            for (double t : tiempos_espera) total_espera += t;
            for (double t: tiempos_procesamiento) total_procesamiento += t;
            num_esperas = tiempos_espera.size();
            num_procesamientos = tiempos_procesamiento.size()
        }

        // calcula el promedio de tiempo de espera y procesamiento
        // se usan operadores para los condicionales en una sola línea y mantener el orden
        promedio_espera = num_esperas > 0 ? total_espera / num_esperas : 0;
        promedio_procesamiento = num_procesamientos > 0 ? total_procesamiento / num_procesamientos : 0;

        // Imprimir resultados
        cout << "\n--- MÉTRICAS DE RENDIMIENTO ---\n";
        cout << "Promedio de tiempo de espera en búfer: " << promedio_espera << " segundos\n";
        cout << "Promedio de tiempo de procesamiento: " << promedio_procesamiento << " segundos\n";
        cout << "--------------------------------\n";
    }
}
