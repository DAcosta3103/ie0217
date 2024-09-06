/**
 * @file Tienda.hpp
 * @brief Headerfile de la clase Tienda, así como sus clases derivadas.
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
#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Cliente.hpp"

using namespace std;

/**
 * @brief Clase Tienda, maneja el algoritmo de las acciones posibles de la tienda virtual
 * 
 */
class Tienda {
    public:
        /**
         * @brief Vector tipo Producto para almacenar los productos disponibles ingresados por el usuario
         * 
         */
        vector<Producto*> productosDisponibles;
        /**
         * @brief Vector tipo Cliente para almacenar los clientes ingresados por el usuario
         * 
         */
        vector<Cliente*> clientes;

        /**
         * @brief Método para agregar un producto nuevo a la tienda
         * Recibe un producto nuevo y lo almacena en el vector 'productosDisponibles'
         * 
         * @param productoNuevo El producto que se ingresará por el usuario, tipo puntero que contiene elementos de la clase Producto
         */
        void agregarProducto(Producto* productoNuevo) {
            productosDisponibles.push_back(productoNuevo);
        }

        /**
         * @brief Método para agregar clientes nuevos
         * Almacena el cliente nuevo en el vector 'clientes'
         * 
         * @param clienteNuevo El cliente que se ingresará por el usuario, es un tipo puntero que contiene elementos de la clase Cliente
         */
        void agregarCliente(Cliente* clienteNuevo) {
            clientes.push_back(clienteNuevo);
        }

        /**
         * @brief Método para manejar la opción de procesar compra
         * Crea un nullptr de tipo Cliente, luego se crea un loop para que se recorra el vector clientes
         * 
         * @param nombreCliente Nombre del cliente del cual se quiere procesar el carrito para la compra
         */
        void procesarCompra(const string& nombreCliente) {
            Cliente* cliente = nullptr;

            for (Cliente* clnt: clientes) {                 /*!< Se recorre el vector 'clientes' obteniendo el nombre de cada uno*/
                if (clnt->getNombre() == nombreCliente) {           
                    cliente = clnt;                         
                    break;
                } 
            }

            if (cliente) {          /*!< como definimos cliente como nullptr, si no se encuentra un cliente, se tiene !cliente.  */
                cliente->mostrarCarrito();
                double totalSinDescuento = cliente->calcularTotal();
                double totalFinal = cliente->aplicarDescuento(totalSinDescuento);

                cout << "El total a pagar por el carrito del cliente " << nombreCliente << " es de " <<  totalFinal << endl;
            } else {
                cout << "El cliente que ha ingresado no coincide con ningún cliente en la base de datos." << endl; 
            }
        }


};












#endif // TIENDA_HPP    