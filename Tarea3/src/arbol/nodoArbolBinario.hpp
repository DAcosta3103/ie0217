#ifndef NODO_ARBOL_BINARIO_HPP
#define NODO_ARBOL_BINARIO_HPP

/**
 * @brief Estructura base para un nodo de un árbol
 * la estructura base NodoArbol contiene los elementos que se recorrerán que tiene un nodo: el valor actual, un puntero hacia la subrama izquierda 
 * y un puntero hacia la *subrama derecha
 */
struct NodoArbol {
    int dato;               // valor actual
    NodoArbol* izquierdo;   // puntero que apunta hacia la subrama izquierda
    NodoArbol* derecho;     // puntero que apunta hacia la subrama derecha
    
    /**
     * @brief Constructor de NodoArbol.
     * 
     * Inicializa el nodo con el valor proporcionado y establece los punteros a las subramas
     * izquierdo y derecho como nullptr.
     * 
     * @param valor El valor para inicializar el nodo.
     */
    NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

#endif // NODO_ARBOL_BINARIO_HPP
