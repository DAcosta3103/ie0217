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
        string nombre, categoria, descripcion;
        int cantidad;
        Componente(const string &nombre, const string &categoria, int cantidad, const string &descripcion);
};

class Inventario {
    private:
        vector<Componente> componentes;
    public:
        agregarComponente(const string& nombre, const string& categoria, int cantidad, const string& descripcion);
        reducirComponente(const string& nombre, int cantidad);
        listarComponentes() const;
        buscarComponente(const string& nombre);

};

#endif //INVENTARIO_HPP