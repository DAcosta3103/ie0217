// En este archivo tenemos las definiciones de lo instanciado en persona.hpp
#include "persona.hpp"  
using namespace std;

// Acá se tiene el constructor, el cual recibe dos argumentos: nombre y edad
Persona::Persona(string nombre, int edad) {
    // La sintaxis 'this' sirve para indicar que estamos trabajando sobre **esta** clase, es decir 'this class'.
    // de esta manera,  el script sabe que aunque haya otro método distinto pero con el mismo nombre, sabrá que en dihca línea nos referimos a la clase raíz
    this->nombre = nombre;      
    this->edad = edad;
}

// Se usan los dos puntos dobles para indicar que getNombre viene de la clase Persona
string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

void Persona::setEdad(int edad) {
    this->edad = edad;

}