#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>
using namespace std;

class Estudiante {
public:
    Estudiante(const string& nombre, int edad);
    void mostrarDatos();

private:
    string nombre;
    int edad;
};

#endif
