#include "sistema.hpp"
#include <thread>
#include <vector>

using namespace std;

int main() {
    int num_clientes = 10;
    int num_operadores = 10;
    vector<thread> clientes, operadores;      // se crean vectores de hilos para manejar los clientes y operadores

    for (int i = 0; i < num_clientes; ++i)
        clientes.emplace_back(cliente, i + 1);

    for (int i = 0; i < num_operadores; ++i)
        operadores.emplace_back(operador, i + 1);

    thread metricas_thread(mostrar_metricas);   // se crea un hilo que emplea la función mostrar_metricas

    metricas_thread.join();
    // se itera sobre cada hilo en ambos vectores y llama a join() en ellos 
    for (auto& c : clientes) c.join(); 
    for (auto& o : operadores) o.join();    

    // se bloquea la ejecución del hilo principal hasta que el hilo metricas_thread termine
    

    return 0;
}