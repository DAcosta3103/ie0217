#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
    private:
        string nombre;
        int edad;

    public:
        // Ya que estamos en el headerfile, solo es necesario escribir las declaraciones/prototipos de las funciones y del constructor
        Persona(string nombre, int edad);
        string getNombre();
        int getEdad();
        void setEdad(int edad);
};


#endif // PERSONA_H