#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>
#include <chrono>
#include <random>

using namespace std;

// Configuración inicial y variables compartidas 
const int BUFFER_SIZE = 10;
queue<int> buffer;
mutex mtx;
condition_variable cv_client, cv_operator;
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE), full_slots(0);

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
            buffer.push(solicitud);
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
        {
            lock_guard<mutex> lock(mtx);    // se protege el acceso con un mutex
            solicitud = buffer.front();     // se define la variable solicitud    
            buffer.pop();                   // se extrae la solicitud mas antigua del buffer
            cout << "Operador " << id << " está procesando solicitud " << solicitud << "\n";
        }

        cv_client.notify_one(); // Notifica que hay espacio en el búfer
        this_thread::sleep_for(chrono::milliseconds(distribution(generator))); // Simula el tiempo de procesamiento
    }
}
