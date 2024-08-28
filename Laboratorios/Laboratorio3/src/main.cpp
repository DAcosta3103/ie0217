#include <iostream>
#include <vector>

#include "empleadoTiempoCompleto.hpp"
#include "empleadoMedioTiempo.hpp"

using namespace std;

int main() {

    vector<Empleado*> empleados;

    empleados.push_back(new EmpleadoTiempoCompleto("Alice", 1, 50000, 5000, 1000));
    empleados.push_back(new EmpleadoMedioTiempo("Bob", 2, 20, 120));
    empleados.push_back(new EmpleadoTiempoCompleto("Charlie", 3, 55000, 4000, 1500));
    empleados.push_back(new EmpleadoMedioTiempo("David", 4, 25, 100));
    empleados.push_back(new EmpleadoTiempoCompleto("Esteban", 10, 150000, 9000, 60000));

    for (const auto& empleado: empleados) {
        empleado->mostrarInformacion();
    }

    for (const auto& empleado: empleados) {
        delete empleado;
    }

    return 0;
}