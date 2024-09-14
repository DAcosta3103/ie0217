/**
 * @file cancion.hpp
 * @brief Headerfile para la clase Cancion
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

#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>

using namespace std;

/**
 * @brief Clase base para las canciones
 * 
 */
class Cancion {
    private:
        string titulo, artista;
        double duracion;

    public:
        /**
         * @brief Constructor para la clase Cancion
         * 
         * @param titulo Título de la canción
         * @param artista Artista de la canción
         * @param duracion Duración de la canción, en minutos
         */
        Cancion(string titulo, string artista, double duracion) : titulo(titulo), artista(artista), duracion(duracion) {}

        /**
         * @brief Método para obtener el Titulo 
         * 
         * @return string 
         */
        string getTitulo() const {return titulo; }

        /**
         * @brief Método para obtener el Artista 
         * 
         * @return string 
         */
        string getArtista() const {return artista;}

        /**
         * @brief Método para obtener la Duracion 
         * 
         * @return double 
         */
        double getDuracion() const {return duracion;}

};





#endif