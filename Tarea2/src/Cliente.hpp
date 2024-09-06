/**
 * @file Cliente.hpp
 * @brief Headerfile de la clase Producto, así como sus clases derivadas.
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

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Producto.hpp"
#include <vector>


/**
 * @brief Clase Cliente, base para manejar los datos de los clientes
 * 
 */
class Cliente {
    public:
        /**
         * @brief Atributo para el nombre del cliente
         * 
         */ 
        string nombre;
        /**
         * @brief Se crea un vector 'carrito' para guardar los productos pertenecientes al cliente
         * 
         */
        vector<Producto*> carrito;        /*!< vector de tipo puntero de Producto */
        
        /**
         * @brief Construtor para la clase Cliente
         * El constructor solo inicializa el nombre, ya que 'carrito' como tal no se puede inicializar por el usuario
         * 
         * @param nombre Nombre del cliente
         */
        Cliente(string& nombre) : nombre(nombre)  {}        

        
        /**
         * @brief método para agregar productos al carrito
         * Añade un producto al vector 
         * 
         * @param producto Puntero tipo clase Producto
         */
        void agregarProducto(Producto* producto) {          
           carrito.push_back(producto);
        }

        /**
         * @brief Método para obtener el nombre del cliente 
         * 
         * @return Nombre del cliente
         */
        string getNombre() const {
            return nombre;
        }

        /**
         * @brief Se crea un método virtual pura para el descuento correspondiente del tipo de cliente
         * 
         * @param valor Placeholder para el total del carrito
         */
        virtual double aplicarDescuento(double valor) const = 0;      

        /**
         * @brief Método para calcular el precio total del carrito de productos
         * 
         * @return La suma de los precios de los productos del carrito
         */
        double calcularTotal() const {
            double total = 0;
            for(Producto* producto: carrito) {                /*!< el condicional significa "para todo producto, donde producto es un puntero de 'Producto' (la clase), en el rango de 'carrito' (un vector)" */ 
                total += producto->getPrecio();
            }
            return total;
        }

        /**
         * @brief Muestra los productos en el carrito del cliente.
         * La mayoría de la lógica está hecha por el método mostrarInfo, 
         * el cual se llama desde el puntero producto tipo Producto
         * 
         */
        void mostrarCarrito() {
            cout << "Carrito del cliente " << nombre << ":\n";

            if (carrito.empty()){
                cout << "No hay elementos en el carrito.";
            } else {
                for (Producto* producto : carrito) {
                    producto->mostrarInfo();
                }
            }
        }
};

/**
 * @brief Clase derivada de Cliente para los clientes regulares (sin descuento)
 * 
 */
class ClienteRegular: public Cliente {
    public:
        /**
         * @brief Construtor para la clase Cliente Regular
         * 
         * @param nombre Nombre del cliente regular
         */
        ClienteRegular(string& nombre) : Cliente(nombre) {}

        /**
         * @brief Método para aplicar el descuento del Cliente Regular
         * 
         * Como los clientes regulares no reciben descuento, por lo que retorna el total sin cambios
         * @param valor Placeholder para el total 
         * @return El total sin cambios (sin descuento)
         */
        double aplicarDescuento(double valor) const override {
            return Cliente::calcularTotal();
        }
};

/**
 * @brief Clase derivada de Cliente para los clientes premium (con descuento) 
 * 
 */
class ClientePremium: public Cliente {
    public:
        /**
         * @brief Atributo para el descuento respectivo de cada Cliente Premium
         * 
         */
        double descuento;

        /**
         * @brief Construtor para la clase Cliente Premium
         * 
         * @param nombre Nombre del cliente premium
         * @param descuento Descuento perteneciente al cliente premium (0 < descuento < 1)
         */
        ClientePremium(string& nombre, double descuento) : Cliente(nombre), descuento(descuento) {}

        /**
         * @brief Método para aplicar el descuento respectivo de cada cliente
         * 
         * @param total Suma total de los precios de los productos del carrito
         * @return double 
         */
        double aplicarDescuento(double total) const override {
            return (total*(1 - descuento));     // retorna el valor de la compra con el descuento aplicado
        }
};

#endif // CLIENTE_HPP