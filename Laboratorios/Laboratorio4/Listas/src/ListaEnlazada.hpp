#ifndef LISTAENLAZADA_HPP
#define LISTAENLAZADA_HPP

#include "Nodo.hpp"
#include <iostream>

class ListaEnlazada {
private:
    // Se crea un puntero de tipo Nodo llamado cabeza
    Nodo* cabeza;

public: 
    // El constructor va a crear en el elemento cabeza
    ListaEnlazada() : cabeza(nullptr) {}
    
    // Destructor
    ~ListaEnlazada() {
        while (cabeza != nullptr) {     // cuando cabeza no es el último elemento
            Nodo* temp = cabeza;        // la cabeza actual queda en un puntero temporal
            cabeza = cabeza->siguiente;     // defino como cabeza el siguiente
            delete temp;                // borro al cabeza actual guardada en una variable temporal
        }
    }

    //  Función para insertar un número al inicio de la lista
    // La función recibe como parámetro el número entero que el usuario desea ingresar, en la variable 'valor'
    void insertarInicio(int valor) {            
        Nodo* nuevoNodo = new Nodo(valor);      // creamos un nodo (puntero tipo Nodo) llamado nuevoNodo, la palabra 'new' crea un puntero que apunta al constructor que le asigna valor a dato
        nuevoNodo->siguiente = cabeza;          // el puntero que acabamos de crear pasa a la dirección donde apunta 'siguiente',
        cabeza = nuevoNodo;                     // el puntero cabeza apunta al nuevo nodo, el cual es el nuevo valor al inicio
    }

    // función para insertar un valor al final de la lista
    // el parámetro que recibe la función es igual que insertarInicio()
    void insertarFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
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

    // función para eliminar
    void eliminar(int valor) {
        if (cabeza == nullptr) return;

        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr && temp->siguiente->dato != valor) {
            temp = temp->siguiente;
        }

        if (temp->siguiente != nullptr) {
            Nodo* nodoAEliminar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete nodoAEliminar;
        }
    }

    // funcion para imprimir
    void imprimir() const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        std::cout << "null" << std::endl;
    }

    bool buscar(int valor) const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            if (temp->dato == valor) return true;
            temp = temp->siguiente;
        }
        return false;
    }
};

#endif