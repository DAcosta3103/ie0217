#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Producto.hpp"
#include <vector>


/**
 * @brief Clase base para manejar los datos de los clientes, una de las tres clases principales
 * 
 */
class Cliente {
    public:
        string nombre;
        vector<Producto*> carrito;       // vector de tipo puntero de Producto
        
        Cliente(string& nombre) : nombre(nombre)  {}        // el constructor solo inicializa el nombre, ya que 'carrito' como tal no se puede inicializar por el usuario

        // función para agregar un producto al carrito
        void agregarProducto(Producto* producto) {          
           carrito.push_back(producto);
        }

        string getNombre() const {
            return nombre;
        }

        virtual double aplicarDescuento(double valor) const = 0;      

        double calcularTotal() const {
            double total = 0;
            for(Producto* producto: carrito) {                 // el condicional significa "para todo producto, donde producto es un puntero de 'Producto' (la clase), en el rango de 'carrito' (un vector)"
                total += producto->getPrecio();
            }
            return total;
        }

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
 * @brief Clase responsable de manejar los clientes sin descuento
 * 
 */
class ClienteRegular: public Cliente {
    public:
        ClienteRegular(string& nombre) : Cliente(nombre) {}

        double aplicarDescuento(double valor) const override {
            return Cliente::calcularTotal();
        }
};

/**
 * @brief Clase responsable de manejar los clientes con descuento
 * 
 */
class ClientePremium: public Cliente {
    public:
        double descuento;

        ClientePremium(string& nombre, double descuento) : Cliente(nombre), descuento(descuento) {}

        double aplicarDescuento(double total) const override {
            return (total*(1 - descuento));     // retorna el valor de la compra con el descuento aplicado
        }
};



#endif // CLIENTE_HPP