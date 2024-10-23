#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

const int NUM_THREADS = 100;  // Número de hilos
const int NUM_INCREMENTS = 100000;  // Número de incrementos por hilo

int counter = 0;  // Contador compartido
std::mutex mtx;   // Mutex para proteger el acceso al contador

// Función que incrementa el contador sin protección
void increment_without_lock() {
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        counter++;
    }
}

// Función que incrementa el contador con protección de mutex
void increment_with_lock() {
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main() {
    // Ejemplo 1: Incremento sin protección (condición de carrera)
    counter = 0;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.push_back(std::thread(increment_without_lock));
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Resultado sin protección: " << counter << std::endl;

    // Ejemplo 2: Incremento con protección (uso de mutex)
    counter = 0;
    threads.clear();

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.push_back(std::thread(increment_with_lock));
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Resultado con protección: " << counter << std::endl;

    return 0;
}
