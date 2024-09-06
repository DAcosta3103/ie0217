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
        
        Producto(string& nombre, double precio) : nombre(nombre), precio(precio) {}

        double getPrecio() const {
            return precio;
        }

        string getNombre() const {
            return nombre;
        }

        virtual void mostrarInfo() const = 0;
        
};

/**
 * @brief Clase derivada de producto, encargada de los productos digitales ingresados
 * 
 */
class ProductoDigital: public Producto {

    public:
        int id;

        ProductoDigital(string& nombre, double precio, int id) : Producto(nombre, precio), id(id) {}

        int getID() const {
            return id;
        }

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
        double peso;

        ProductoFisico(string& nombre, double precio, double peso): Producto(nombre, precio), peso(peso) {}

        double getPeso() const {
            return peso;
        }      

        void mostrarInfo() const override {
            cout << "Producto Físico - Nombre: " << nombre << ", Precio: " << precio << ", Peso: " << peso << endl;
        }

};

#endif //PRODUCTO_HPP