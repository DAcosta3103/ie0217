/**
 * @file Producto.hpp
 * @brief Headerfile de la clase Cliente, así como sus clases derivadas.
 *  Se declaran y se definen todos los métodos pertenecientes a las clases
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
#ifndef PRODUCTO_HPP
#define PRODUTCO_HPP

#include <iostream>
#include <string>

using namespace std;


/**
 * @brief Clase base Producto, una de las tres clases principales del srcipt
 */
class Producto {
    public:

        /**
         * @brief Nombre del producto
         * 
         */
        string nombre;

        /**
         * @brief Precio del producto
         * 
         */
        double precio;
        
        /**
         * @brief Constructor de la clase producto
         * 
         * @param nombre Nombre del producto 
         * @param precio Precio del producto
         */
        Producto(string& nombre, double precio) : nombre(nombre), precio(precio) {}

        /**
         * @brief Método para obtener el precio del producto
         * 
         * @return El precio del producto
         */
        double getPrecio() const {
            return precio;
        }

        /**
         * @brief Método para obtener el nombre del producto
         * 
         * @return Nombre del producto 
         */
        string getNombre() const {
            return nombre;
        }

        /**
         * @brief Método virtual para mostrar los detalles del producto 
         * 
         */
        virtual void mostrarInfo() const = 0;
        
};

/**
 * @brief Clase derivada de Producto, encargada de los productos digitales ingresados
 * 
 */
class ProductoDigital: public Producto {

    public:
        /**
         * @brief Atributo para el ID del producto digital
         * 
         */
        int id;

        /**
         * @brief Construtor para la clase Producto Digital
         * 
         * @param nombre 
         * @param precio 
         * @param id 
         */
        ProductoDigital(string& nombre, double precio, int id) : Producto(nombre, precio), id(id) {}

        /**
         * @brief Método para obtener el ID del producto digital
         * 
         * @return ID del producto digital
         */
        int getID() const {
            return id;
        }

        /**
         * @brief Método para mostrar la información del producto digital
         * 
         */
        void mostrarInfo() const override {
            cout << "Producto Digital - Nombre: " << nombre << ", Precio: " << precio << ", ID: " << id << endl;
        }

};

/**
 * @brief Clase derivada de producto, encargada de los productos digitales
 * 
 */
class ProductoFisico: public Producto {
    public:
        /**
         * @brief Atributo para el peso del producto físico
         * 
         */
        double peso;

        /**
         * @brief Construtor para la clase Producto Fisico
         * 
         * @param nombre 
         * @param precio 
         * @param peso 
         */
        ProductoFisico(string& nombre, double precio, double peso): Producto(nombre, precio), peso(peso) {}

        /**
         * @brief Método para obtener el Peso 
         * 
         * @return peso 
         */
        double getPeso() const {
            return peso;
        }      

        /**
         * @brief Método para mostrar la información del producto físico
         * 
         */
        void mostrarInfo() const override {
            cout << "Producto Físico - Nombre: " << nombre << ", Precio: " << precio << ", Peso: " << peso << endl;
        }

};

#endif //PRODUCTO_HPP