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
        
        Cliente(string nombre) : nombre(nombre)  {}        // el constructor solo inicializa el nombre, ya que 'carrito' como tal no se puede inicializar por el usuario

        void agregarProducto(Producto* producto) {
           carrito.push_back(producto);
        }

        double calcularTotal() const {
            double total = 0;
            for(Producto* producto : carrito) {                 // el condicional significa "para todo producto, donde producto es un puntero de 'Producto' (la clase), en el rango de 'carrito' (un vector)"
                total += producto->getPrecio();
            }
            return total;
        }

        virtual void aplicarDescuento(double descuento) const = 0;      

};

/**
 * @brief Clase responsable de manejar los clientes sin descuento
 * 
 */
class ClienteRegular: public Cliente {
    public:
        ClienteRegular(string nombre) : Cliente(nombre) {}

        double aplicarDescuento(double descuento) const override {
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

        ClientePremium(string nombre, double descuento) : Cliente(nombre), descuento(descuento) {}

        double aplicarDescuento(double descuento) const override {
            descuento *= 0.01;
            double total = Cliente::calcularTotal();
            
            return (total - total * descuento);
        }
};



#endif // CLIENTE_HPP