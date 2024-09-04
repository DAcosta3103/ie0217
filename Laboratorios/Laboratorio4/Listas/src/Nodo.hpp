#ifndef NODO_HPP
#define NODO_HPP

/* Se crea la estructura Nodo, en lugar de una clase. La diferencia principal entre una estructura y una clase es que
las estructuras definen predeterminadamente como públicos sus atributos, y las clases los definen como privados*/
struct Nodo {

    int dato;                   // Se crea el atributo dato
    Nodo* siguiente;            // Se crea un puntero que señala a la estructura Nodo, y se le llama siguiente
    
    
    // Función constructora de la estructura Nodo
    // Recibe un valor y le asigna ese valor al atributo 'dato', mientras que el puntero 'siguiente' apunta a NULL
    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

#endif
