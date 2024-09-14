/**
 * @file nodoArbolBinario.hpp
 * @brief Headerfile para la clase NodoArbol
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
#ifndef NODO_ARBOL_BINARIO_HPP
#define NODO_ARBOL_BINARIO_HPP

/**
 * @brief Clase base para un nodo de un árbol
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
