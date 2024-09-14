/**
 * @file nodoLista.hpp
 * @brief Headerfile para la clase Nodo, encargada de manejar la lógica del paso entre nodos.
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

#ifndef NODO_LISTA_HPP
#define NODO_LISTA_HPP
#include "cancion.hpp"

/**
 * @brief Estructura Nodo encargada del funcionamiento de los nodos en la lista enlazada
 * 
 */
class Nodo {
    public:
        Cancion cancion;                   // Se crea el atributo dato
        Nodo* siguiente;            // Se crea un puntero que señala a la estructura Nodo, y se le llama siguiente
    
    
    // Función constructora de la estructura Nodo
    // Recibe un valor y le asigna ese valor al atributo 'dato', mientras que el puntero 'siguiente' apunta a NULL
    Nodo(const Cancion& cancion) : cancion(cancion), siguiente(nullptr) {}
};

#endif  
