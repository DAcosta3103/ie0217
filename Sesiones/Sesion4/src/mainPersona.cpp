#include <iostream>
#include "persona.hpp"

using namespace std;

int main () {
    Persona p("Juan", 25);          // Declaramos a 'p', de tipo Persona, y le pasamos los parámetros de la clase

    cout << "Nombre: " << p.getNombre() << endl;    // Usando el método getNombre, recibimos el nombre de la persona p
    cout << "Edad: " << p.getEdad() << endl;        // se hace lo mismo para la edad

    p.setEdad(26);                  // Se usa el método setEdad 'p'

    cout << "Nueva edad: " << p.getEdad() << endl;  // se vuelve a pedir la edad
    return 0;
}