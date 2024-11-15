#include "inventario.hpp"


using namespace std;

// Se maneja la inclusión de un componente nuevo en el vector 'componentes', de la clase Inventario
void Inventario::agregarComponente(const string& nombre, const string& categoria, int cantidad, const string& descripcion) {
    // entra al bucle para buscar el componente, en caso de que sea repetido
    for (auto& componente : componentes) {
        
        if (componente.nombre == nombre) {
            componente.cantidad += cantidad;    // añade la cantidad de componentes que el usuario quiera
            return;
        }
    }
    // si el componente no es repetido, solamente lo añade
    componentes.emplace_back(nombre, categoria, cantidad, descripcion);
}

void Inventario::reducirComponente(const string& nombre, int cantidad) {
    // se busca si el componente está en la lista
    for (auto& componente : componentes) {  
        if (componente.nombre == nombre) {  // se encuentra el componente
            if (componente.cantidad < cantidad) throw runtime_error("Cantidad insuficiente en el inventario."); // se maneja que no se puedan tener cantidades negativas
            componente.cantidad -= cantidad;
            return;
        }
    }
    // si no se encuentra el componente
    throw runtime_error("Componente no encontrado");
}

void Inventario::listarComponentes() const {
    if (componentes.empty()) {
        cout << "El inventario está vacío." << endl;
        return;
    }
    for (auto& componente : componentes) {
        cout << "Nombre: " << componente.nombre << ", Categoría: " << componente.categoria << ", Cantidad: " << componente.cantidad << ", Descripcion: " << componente.descripcion << endl; 
    }
}

void Inventario::buscarComponente(const string& nombre) {
    // se busca el componente por nombre
    for (auto& componente : componentes) {
        // si se encuentra, se imprime la información
        if (componente.nombre == nombre) {
            cout << "Nombre: " << componente.nombre << ", Categoría: " << componente.categoria << ", Cantidad: " << componente.cantidad << ", Descripcion: " << componente.descripcion << endl; 
            return;      
        }
    }
    // si no se encuentra, se imprime aviso
    cout << "Componente no encontrado." << endl;
}