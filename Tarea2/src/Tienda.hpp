#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Cliente.hpp"

using namespace std;

class Tienda {
    public:
        vector<Producto*> productosDisponibles;
        vector<Cliente*> clientes;

        void agregarProducto(string productoNuevo) {
            productosDisponibles.push_back(productoNuevo);
        }

        void agregarCliente(string clienteNuevo) {
            clientes.push_back(clienteNuevo);
        }

        void procesarCompra(const string nombreCliente) {
            Cliente* cliente;
            for (string cliente: clientes) {
                if (cliente->nombre == nombreCliente) {
                    cliente->mostrarCarrito();
                    double total = cliente->aplicarDescuento();
                    cout << "El total a pagar por el carrito del cliente " << nombreCliente << " es de " <<  total << endl;
                }
                else {
                    cout << "El cliente que ha ingresado no coincide con ningún cliente en la base de datos." << endl;
                }
            }
        }


};












#endif // TIENDA_HPP    