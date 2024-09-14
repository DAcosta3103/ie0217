#ifndef NODO_LISTA_HPP
#define NODO_LISTA_HPP
#include "cancion.hpp"

/**
 * @brief Estructura Nodo encargada del funcionamiento de los nodos en la lista enlazada
 * 
 */
class Nodo {
    public:
        Cancion* cancion;                   // Se crea el atributo dato
        Nodo* siguiente;            // Se crea un puntero que señala a la estructura Nodo, y se le llama siguiente
    
    
    // Función constructora de la estructura Nodo
    // Recibe un valor y le asigna ese valor al atributo 'dato', mientras que el puntero 'siguiente' apunta a NULL
    Nodo(Cancion& cancion) : cancion(cancion), siguiente(nullptr) {}
};

#endif
