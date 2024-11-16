#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>


using namespace std;

class Componente {
    public:
        string nombre;
        string categoria;
        int cantidad;
        string descripcion;
        
        Componente(const string &nombre, const string &categoria, int cantidad, const string &descripcion);
};

class Inventario {
    private:
        vector<Componente> componentes;
    public:
        void agregarComponente(const string& nombre, const string& categoria, int cantidad, const string& descripcion);
        void reducirComponente(const string& nombre, int cantidad);
        void listarComponentes() const;
        void buscarComponente(const string& nombre);

};

#endif //INVENTARIO_HPP