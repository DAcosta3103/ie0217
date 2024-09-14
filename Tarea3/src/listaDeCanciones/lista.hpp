/**
 * @file lista.hpp
 * @brief Headerfile de la clase ListaEnlazada
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

#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodoLista.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Clase principal que maneja la Lista Enlazada
 * 
 */
class ListaEnlazada {
    private:
        Nodo* cabeza;
    
    public:
        /**
         * @brief Construtor para la clase Lista Enlazada
         * 
         */
        ListaEnlazada();

        /**
         * @brief Destructor para la clase Lista Enlazada
         * 
         */
        ~ListaEnlazada();

        /**
         * @brief Método para inicializar la lista de canciones con tres canciones predefinidas
         * 
         */
        void inicializar();
        
        /**
         * @brief Método para insertar una canción al inicio de la lista
         * 
         * @param cancion Cancion por insertar 
         */
        void insertarInicio(const Cancion& cancion);

        /**
         * @brief Método para insertar una canción al final de la lista
         * 
         * @param cancion Canción por insertar
         */
        void insertarFinal(const Cancion& cancion);

        /**
         * @brief Método para sertar una canción en una posición en específico de la lista
         * 
         * @param cancion Cancion por insertar
         * @param posicion Posicion de la lista en dónde ingresar la canción
         */
        void insertarPosicion(const Cancion& cancion, int posicion);

        /**
         * @brief Método para eliminar una canción
         * 
         * @param nombre Canción por eliminar
         */
        void eliminarCancion(const string& nombre);

        /**
         * @brief Método para modificar una canción
         * 
         * @param nombre nombre de la canción por modificar
         * @param nuevaCancion El nuevo objeto canción con los datos nuevos
         */
        void modificarCancion(const string& nombre, const Cancion& nuevaCancion);

        /**
         * @brief Método para imprimir la lista de canciones
         * 
         */
        void imprimirLista() const;


};





#endif