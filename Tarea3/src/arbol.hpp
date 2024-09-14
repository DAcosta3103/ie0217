#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "nodoArbol.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Clase principal para manejar el árbol binario
 * 
 */
class ArbolBinario  {
    private:
        /**
         * @brief El nodo raíz (base) del árbol
         */
        NodoArbol* raiz;

        /**
         * @brief Método para insertar nuevos nodos desde la terminal
         * 
         * @param nodo La dirección adonde se va a añadir el nuevo nodo, dependiendo de su valor
         * @param valor El valor del nuevo nodo
         */
        void insertarNodo(NodoArbol*& nodo, int valor);

        /**
         * @brief Método para obtener el valor mínimo del árbol
         * 
         * Este método nos será útil en el método para eliminar nodos con dos subramas
         * 
         * @param nodo El nodo a eliminar
         * @return NodoArbol* La dirección del nodo menor
         */

        NodoArbol* getMinimo(NodoArbol* nodo) const;

        /**
         * @brief Método para eliminar un nodo deseado
         * 
         * @param nodo Un puntero al nodo actual del árbol donde la función está operando.
         * @param valor El valor del nodo a eliminar
         * @return NodoArbol* La dirección al nuevo nodo que tomó el lugar del eliminado 
         */
        NodoArbol* eliminarNodo(NodoArbol* nodo, int valor);

        /**
         * @brief Función para recorrer e imprimir el árbol en orden
         * 
         * @param nodo Un puntero al nodo actual de árbol donde la función está operando
         */
        void inOrden(NodoArbol* nodo) const;

        /**
         * @brief Método para obtener la altura del árbol
         * 
         * @param nodo Un puntero al nodo actual de árbol donde la función está operandovv
         * @return La altura del árbol 
         */
        int altura(NodoArbol* nodo) const;

        /**
         * @brief Método para verificar si el árbol está balanceado 
         * 
         * @param nodo Un puntero al nodo actual de árbol donde la función está operando
         * @return true si el arbol está balanceado 
         * @return false si el árbol no está balanceado
         */
        bool estaBalanceado(NodoArbol* nodo) const;
    
    public:
        /**
         * @brief Construtor para la clase Arbol Binario
         */
        ArbolBinario();

        /**
         * @brief Método público para llamar a la función de insertar
         * @param valor El valor del nodo a insertar
         */
        void insertar(int valor);

        /**
         * @brief Método público para llamar a la función de recorrer el árbol en orden
         */
        void inOrden() const;

        /**
         * @brief Método público para llamar a la función para obtener la altura del árbol
         */
        int altura();

         /**
         * @brief Método público para llamar a la función de verificar el balanceo del árbol
         */
        bool estaBalanceado() const;

};

#endif // ARBOL_HPP