#include <iostream>
#include "estudiante.hpp"

using namespace std;

Estudiante::Estudiante(const string& nombre, int edad)
    : nombre(nombre), edad(edad) {}

void Estudiante::mostrarDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
