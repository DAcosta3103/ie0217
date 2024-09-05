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

        string nombre;
        double precio;
        
        Producto(string nombre, double precio) : nombre(nombre), precio(precio) {}

        double getPrecio() {
            return precio;
        }

        string getNombre() {
            return nombre;
        }
};

/**
 * @brief Clase derivada de producto, encargada de los productos digitales ingresados
 * 
 */
class ProductoDigital: public Producto {

    public:
        int id;

        ProductoDigital(string nombre, double precio, int id) : nombre(nombre), precio(precio), id(id) {}

        int getID() {
            return id;
        }

};

/**
 * @brief Clase derivada de producto, encargada de los productos digitales
 * 
 */
class ProductoFisico: public Producto {
    public:
        double peso;

        ProductoFisico (string nombre, double precio, double peso): nombre(nombre), precio(precio), id(id) {}

        double getPeso() {
            return peso;
        }      
};







#endif //PRODUCTO_HPP