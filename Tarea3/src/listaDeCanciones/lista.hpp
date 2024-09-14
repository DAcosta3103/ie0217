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
        void insertarInicio(Cancion& cancion);

        /**
         * @brief Método para insertar una canción al final de la lista
         * 
         * @param cancion Canción por insertar
         */
        void insertarFinal(Cancion& cancion);

        /**
         * @brief Método para sertar una canción en una posición en específico de la lista
         * 
         * @param cancion Cancion por insertar
         * @param posicion Posicion de la lista en dónde ingresar la canción
         */
        void insertarPosicion(Cancion& cancion, int posicion);

        /**
         * @brief Método para eliminar una canción
         * 
         * @param nombre Canción por eliminar
         */
        void eliminarCancion(string& nombre);

        /**
         * @brief Método para modificar una canción
         * 
         * @param nombre nombre de la canción por modificar
         * @param nuevaCancion El nuevo objeto canción con los datos nuevos
         */
        void modificarCancion(string& nombre, Cancion& nuevaCancion);

        /**
         * @brief Método para imprimir la lista de canciones
         * 
         */
        void imprimirLista() const;


};





#endif