#include "empleadoTiempoCompleto.hpp"

using namespace std;

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion): Empleado (nombre, id, salario), bonificacion(bonificacion), deduccion(deduccion) {}

void EmpleadoTiempoCompleto::setBonificacion(double boni) {
    this->bonificacion = boni;      // Si a un puntero quiero sacarle el registro, uso un asterisco
}

void EmpleadoTiempoCompleto::setDeduccion(double dedu) {
    this->deduccion = dedu;
}

double EmpleadoTiempoCompleto::getSalario() const {
    return salario + bonificacion - deduccion;
}

void EmpleadoTiempoCompleto::mostrarInformacion() const {
    cout << *this << ", Bonificacion: " << bonificacion << ", Dedccion: " << deduccion << endl;
    // this es como un puntero que apunta hacia la clase, y lo dereferenciamos utilizando el asterisco
    // asimismo, 'cout << *this' esta declarado en empleado.cpp, lo cual nos va a dar la informacion proveniente de la clase empleado
}



