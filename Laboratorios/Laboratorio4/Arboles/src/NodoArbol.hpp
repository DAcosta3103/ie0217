#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

// la estructura base NodoArbol contiene los elementos que se recorrerán que tiene un nodo: el valor actual, un puntero hacia la subrama izquierda y un puntero hacia la subrama derecha
struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

    // el parámetro que se le ingresa al constructor es el valor que tomará el atributo dato 
    NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

#endif
