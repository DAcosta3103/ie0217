#include "empleadoMedioTiempo.hpp"

using namespace std;

EmpleadoMedioTiempo::EmpleadoMedioTiempo(const string &nombre, int id, double tarifaPorHora, int horasTrabajadas) : Empleado(nombre, id, tarifaPorHora*horasTrabajadas), tarifaPorHora(tarifaPorHora), horasTrabajadas(horasTrabajadas) {}

void EmpleadoMedioTiempo::setHorasTrabajadas(int horas) {
    this->horasTrabajadas = horas;
}

void EmpleadoMedioTiempo::setTarifaPorHora(double tarifa) {
    this->tarifaPorHora = tarifa;
}

double EmpleadoMedioTiempo::getSalario() const {
    return tarifaPorHora * horasTrabajadas;
}

void EmpleadoMedioTiempo::mostrarInformacion() const {
    cout << *this << ", Horas trabajdas: " << horasTrabajadas << ", Tarifa por hora: " << tarifaPorHora << endl;
}