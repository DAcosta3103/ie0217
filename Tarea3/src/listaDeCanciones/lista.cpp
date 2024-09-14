/**
 * @file lista.cpp
 * @brief Archivo fuente para la clase ListaEnlazada
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

#include "lista.hpp"
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Constructor para la clase Lista Enlazada
 * 
 */
ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

/**
 * @brief Destructor para la clase Lista Enlazada
 */
ListaEnlazada::~ListaEnlazada() {
    while (cabeza != nullptr) {     // cuando cabeza no es el último elemento
        Nodo* temp = cabeza;        // la cabeza temp queda en un puntero temporal
        cabeza = cabeza->siguiente;     // defino como cabeza el siguiente
        delete temp;                // borro al cabeza temp guardada en una variable temporal
    }
}


/**
 * @brief Método para inicializar la lista de canciones con tres canciones predefinidas
 * 
 */
void ListaEnlazada::inicializar() {
    insertarFinal(Cancion("Mother", "Pink Floyd", 5));
    insertarFinal(Cancion("Eye in the Sky", "The Alan Parsons Project", 4.5));
    insertarFinal(Cancion("Black", "Pearl Jam", 4));
}

/**
 * @brief Método para insertar una canción al inicio de la lista
 * 
 * @param cancion Cancion por insertar 
 */
void ListaEnlazada::insertarInicio(const Cancion& cancion) {            
    Nodo* nuevoNodo = new Nodo(cancion);      // creamos un nodo (puntero tipo Nodo) llamado nuevoNodo, la palabra 'new' crea un puntero que apunta al constructor que le asigna cancion a dato
    nuevoNodo->siguiente = cabeza;          // el puntero que acabamos de crear pasa a la dirección donde apunta 'siguiente',
    cabeza = nuevoNodo;                     // el puntero cabeza apunta al nuevo nodo, el cual es el nuevo cancion al inicio
}


/**
 * @brief Método para insertar una canción al final de la lista
 * 
 * @param cancion Cancion por insertar 
 */
void ListaEnlazada::insertarFinal(const Cancion& cancion) {
    Nodo* nuevoNodo = new Nodo(cancion);
    if (cabeza == nullptr) {        // si ya 'cabeza' es el final, no entramos al if y se procede directamente a insertar un número
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}


/**
 * @brief Método para sertar una canción en una posición en específico de la lista
 * 
 * @param cancion Cancion por insertar
 * @param posicion Posicion de la lista en dónde ingresar la canción
 */ 
void ListaEnlazada::insertarPosicion(const Cancion& cancion, int posicion) {
    if (posicion <= 0) {
        insertarInicio(cancion);
        return;
    }
    
    Nodo* nuevoNodo = new Nodo(cancion);
    Nodo* temp = cabeza;
    for (int i = 1; i < posicion && temp->siguiente != nullptr; i++) {
        temp = temp->siguiente;
    }
    nuevoNodo->siguiente = temp->siguiente;
    temp->siguiente = nuevoNodo;
}

/**
 * @brief Método para eliminar una canción
 * 
 * @param nombre Canción a eliminar
 */
void ListaEnlazada::eliminarCancion(const string& nombre) {
    Nodo* actual = cabeza;
    Nodo*  anterior = nullptr;

    // busca el nodo a eliminar
    while (actual != nullptr && actual->cancion.getTitulo() != nombre) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // si no se encuentra el nodo
    if (actual == nullptr) {
        cout << "La canción no fue encontrada en la lista." << endl;
    }

    // si el nodo a eliminar es la cabeza
    if (anterior == nullptr) {  
        cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;  // liberamos memoria
    cout << "La canción ha sido eliminada." << endl;
}

/**
* @brief Método para modificar una canción
* 
* @param nombre nombre de la canción por modificar
* @param nuevaCancion El nuevo objeto canción con los datos nuevos
*/
void ListaEnlazada::modificarCancion(const string& nombre, const Cancion& nuevaCancion) {
    Nodo* temp = cabeza;

    // se busca el nodo
    while (temp != nullptr && temp->cancion.getTitulo() != nombre) {
        temp = temp->siguiente;
    }

    if (temp != nullptr) {            // se encontró la canción, procedemos a modificarla
        temp->cancion = nuevaCancion;         
        cout << "Canción modificada." << endl;
    } else {
        cout << "Canción no encontrada." << endl;
    }
}

/**
 * @brief Método para imprimir la lista de canciones
 * 
 */
void ListaEnlazada::imprimirLista() const {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        cout << "Título: " << temp->cancion.getTitulo() << " - Artista: " 
                  << temp->cancion.getArtista() << " (Duración de " 
                  << temp->cancion.getDuracion() << " mins)" << endl;
        temp = temp->siguiente;
    }
}

