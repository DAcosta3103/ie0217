  
#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

#include "NodoArbol.hpp"
#include <iostream>
#include <algorithm>

class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;

    /* Los nodos son múltiples objetos que solo tienen relación con la lógica que les damos
    Hay que tener en cuenta que el nodo contiene 3 cosas: el puntero hacia la izquierda del nodo, el puntero hacia la derecha, y el valor actual del nodo.
    La comparación se hace ya que si lo que está en el nodo siguiente es mayor, este estará situado a la derecha del nodo actual; 
    por otro lado, a la izquierda del nodo actual irán los valores menores
    */
    void insertarNodo(NodoArbol*& nodo, int valor) {
        if (nodo == nullptr) {
            nodo = new NodoArbol(valor);        // Al inicio si no tenemos nada, creamos un nodo
        } else if (valor < nodo->dato) {        // Si el valor ingresado es menor al dato:
            insertarNodo(nodo->izquierdo, valor);   // entra al izquierdo si TRUE
        } else {
            insertarNodo(nodo->derecho, valor);     // entra al derecho si FALSE
        }
    }

    /* Las funciones de búsqueda por in, pos y pre orden son recursivas 
    preorden: primero, el nodo raíz. Luego, todos los nodos en el subárbol izquierdo. Finalmente todos los nodos en el subárbol derecho.
    inorden: primero, todos los nodos en el subárbol izquierdo. Luego, el nodo raíz. Finalmente todos los nodos en el subárbol derecho.
    posorden: primero, todos los nodos en el subárbol izquierdo. Luego, todos los nodos en el subárbol derecho. Finalmente, el nodo raíz.
    */
    void preOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            std::cout << nodo->dato << " ";
            preOrden(nodo->izquierdo);
            preOrden(nodo->derecho);
        }
    }

    void inOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            inOrden(nodo->izquierdo);
            std::cout << nodo->dato << " ";
            inOrden(nodo->derecho);
        }
    }

    void postOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            postOrden(nodo->izquierdo);
            postOrden(nodo->derecho);
            std::cout << nodo->dato << " ";
        }
    }

    // función para buscar un nodo, o más específicamente el valor que contiene el nodo
    bool buscarNodo(NodoArbol* nodo, int valor) const {
        if (nodo == nullptr) return false;      // si el nodo es NULL, no hay datos ingresados
        if (nodo->dato == valor) return true;   // si el atributo de la clase (dato) es igual al valor que se busca, devolver TRUE
        if (valor < nodo->dato) return buscarNodo(nodo->izquierdo, valor);  
        return buscarNodo(nodo->derecho, valor);
    }
    
    // función para imprimir en pantalla la altura del arbol
    // Con altura se refiere a: la altura del nodo raíz o la profundidad del nodo más profundo
    int altura(NodoArbol* nodo) const {
        if (nodo == nullptr) return 0;      // la altura es 0
        return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));    // la altura es el recorrido hasta el nodo raíz
    }

    // función para verificar si el arbol está balanceado
    // si un arbol está balanceado es porque la diferencia de altura entre las subramas izqueirad y derecha no es mayor a uno
    bool estaBalanceado(NodoArbol* nodo) const {
        if (nodo == nullptr) return true;


        int alturaIzquierda = altura(nodo->izquierdo);
        int alturaDerecha = altura(nodo->derecho);

        // se aplica la definición, si la diferencia es mayor a 1, no es balanceado
        return std::abs(alturaIzquierda - alturaDerecha) <= 1 &&
               estaBalanceado(nodo->izquierdo) &&
               estaBalanceado(nodo->derecho);
    }

// se llama a todas las funciones para que sean públicas
public:
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    void insertar(int valor) {
        insertarNodo(raiz, valor);
    }

    void preOrden() const {
        preOrden(raiz);
        std::cout << std::endl;
    }

    void inOrden() const {
        inOrden(raiz);
        std::cout << std::endl;
    }

    void postOrden() const {
        postOrden(raiz);
        std::cout << std::endl;
    }

    bool buscar(int valor) const {
        return buscarNodo(raiz, valor);
    }

    int altura() const {
        return altura(raiz);
    }

    bool estaBalanceado() const {
        return estaBalanceado(raiz);
    }
};

#endif