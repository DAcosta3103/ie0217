#ifndef NODO_LISTA_HPP
#define NODO_LISTA_HPP

/**
 * @brief Estructura Nodo encargada del funcionamiento de los nodos en la lista enlazada
 * 
 */
struct Nodo {

    int dato;                   // Se crea el atributo dato
    Nodo* siguiente;            // Se crea un puntero que señala a la estructura Nodo, y se le llama siguiente
    
    
    // Función constructora de la estructura Nodo
    // Recibe un valor y le asigna ese valor al atributo 'dato', mientras que el puntero 'siguiente' apunta a NULL
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

#endif
