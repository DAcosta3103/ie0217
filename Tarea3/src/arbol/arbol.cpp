/**
 * @file arbol.cpp
 * @brief Archivo fuente para la clase ArbolBinario
 * 
 * MIT License

 * Copyright (c) 2024 DAcosta3103
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "arbol.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Construtor para la clase Arbol Binario
 */
ArbolBinario::ArbolBinario() : raiz(nullptr) {}

/**
 * @brief Método para insertar nuevos nodos desde la terminal
 * 
 * @param nodo La dirección adonde se va a añadir el nuevo nodo, dependiendo de su valor
 * @param valor El valor del nuevo nodo
 */
void ArbolBinario::insertarNodo(NodoArbol*& nodo, int valor) {
    if (nodo == nullptr) {
        nodo = new NodoArbol(valor);        /*!< Se asigna el valor del nodo nuevo en el nodo actual */
    } else if (valor < nodo->dato) {
        insertarNodo(nodo->izquierdo, valor);   /*!< Si el valor es menor, se aplica la función en el subnodo izquierdo */
    } else {
        insertarNodo(nodo->derecho, valor);     /*!< Caso contrario, se aplica en el subnodo derecho */
    }
}

void ArbolBinario::inicializar() {
    insertar(15);
    insertar(10);
    insertar(20);
    insertar(8);
    insertar(12);
    insertar(17);
    insertar(25);
}

 /**
 * @brief Método para obtener el valor mínimo del árbol
 * 
 * Este método nos será útil en el método para eliminar nodos con dos subramas
 * 
 * @param nodo El nodo actual en el que opppera la función
 * @return NodoArbol* La dirección del nodo de menor valor
 */
NodoArbol* ArbolBinario::obtenerMinimo(NodoArbol* nodo) const {
   // Si el nodo actual no tiene subrama izquierda, es el mínimo
   if (nodo->izquierdo == nullptr) {
       return nodo;     // retorna la dirección del nodo menor en la variable nodo  
   }
   // Llamada recursiva para continuar explorando los nodos izquierdos, ene caso de que el actual no sea el menor
   return obtenerMinimo(nodo->izquierdo);
}

 /**
 * @brief Método para eliminar un nodo deseado
 * 
 * @param nodo Un puntero al nodo actual del árbol donde la función está operando.
 * @param valor El valor del nodo a eliminar
 * @return NodoArbol* La dirección al nuevo nodo que tomó el lugar del eliminado 
 */
NodoArbol* ArbolBinario::eliminarNodo(NodoArbol* nodo, int valor) {
    if (nodo == nullptr) return nodo; // Si el nodo es nulo, retornar nulo
     // Búsqueda del nodo a eliminar
    if (valor < nodo->dato) {
        nodo->izquierdo = eliminarNodo(nodo->izquierdo, valor);
    } else if (valor > nodo->dato) {
        nodo->derecho = eliminarNodo(nodo->derecho, valor);
    } else {    // Nodo encontrado, entramos a evaluar los casos distintos
                     
        // Caso 1: El nodo no tiene subramas (es una hoja)
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
            delete nodo;
            return nullptr;
        }   // solo fue necesario eliminar el nodo actual
         // Caso 2: El nodo tiene una sola subrama
        if (nodo->izquierdo == nullptr) {           // Caso 2.1: La subrama es derecha
            NodoArbol* temp = nodo->derecho;        // se guarda el puntero del nodo derecho
            delete nodo;                            // se borra el nodo actual
            return temp;                            // se reemplaza el nodo actual por el que antes era el derecho
        } 
        else if (nodo->derecho == nullptr) {        // Caso 2.2: La subrama es izquierda
            NodoArbol* temp = nodo->izquierdo;      // se guarda el puntero del nodo izquierdo
            delete nodo;                            // se borra el nodo actual
            return temp;                            // el temporal pasa a la dirección del nodo actual
        }
         // Caso 3: El nodo tiene dos subramas
        // para este caso se reemplaza el nodo actual con su sucesor (nodo con el siguiente valor más grande)
        NodoArbol* temp = obtenerMinimo(nodo->derecho); // Obtener el sucesor
        nodo->dato = temp->dato; // Reemplazar el valor del nodo
        nodo->derecho = eliminarNodo(nodo->derecho, temp->dato); // Eliminar el sucesor
    }
    return nodo;
}       
 /**
 * @brief Función para recorrer e imprimir el árbol en orden
 * 
 * @param nodo Un puntero al nodo actual de árbol donde la función está operando
 */
void ArbolBinario::inOrden(NodoArbol* nodo) const {
    if (nodo != nullptr) {
        inOrden(nodo->izquierdo);
        cout << nodo->dato << " ";
        inOrden(nodo->derecho);
    }
}
 /**
 * @brief Método para obtener la altura del árbol
 * 
 * @param nodo Un puntero al nodo actual de árbol donde la función está operandovv
 * @return La altura del árbol 
 */
int ArbolBinario::altura(NodoArbol* nodo) const {
    if (nodo == nullptr) return 0;      // la altura es 0
    return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));    // la altura es el recorrido hasta el nodo raíz
}

 /**
 * @brief Método para verificar si el árbol está balanceado 
 * 
 * @param nodo Un puntero al nodo actual de árbol donde la función está operando
 * @return true si el arbol está balanceado 
 * @return false si el árbol no está balanceado
 */
bool ArbolBinario::estaBalanceado(NodoArbol* nodo) const {
    if (nodo == nullptr) return true;


      int alturaIzquierda = altura(nodo->izquierdo);
    int alturaDerecha = altura(nodo->derecho);

     // se aplica la definición, si la diferencia es mayor a 1, no es balanceado
    return abs(alturaIzquierda - alturaDerecha) <= 1 &&
           estaBalanceado(nodo->izquierdo) &&
           estaBalanceado(nodo->derecho);
}


// métodos públicos


 /**
 * @brief Método público para llamar a la función de insertar
 * @param valor El valor del nodo a insertar
 */
void ArbolBinario::insertar(int valor) {
    insertarNodo(raiz, valor);
}

/**
 * @brief Método público para llamar a la función de eliminar
 * 
 * @param valor Valor del nodo a eliminar
 */
void ArbolBinario::eliminar(int valor) {
    eliminarNodo(raiz, valor);
}
 /**
 * @brief Método público para llamar a la función de recorrer el árbol en orden
 */
void ArbolBinario::inOrden() const {
    inOrden(raiz);
    cout << endl;
}
 /**
 * @brief Método público para llamar a la función para obtener la altura del árbol
 */
int ArbolBinario::altura() {
    return altura(raiz);
}

  /**
 * @brief Método público para llamar a la función de verificar el balanceo del árbol
 */
bool ArbolBinario::estaBalanceado() const {
    return estaBalanceado(raiz);
}
