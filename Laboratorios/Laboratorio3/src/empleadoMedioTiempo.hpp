#ifndef EMPLEADO_MEDIO_TIEMPO_HPP
#define EMPLEADO_MEDIO_TIEMPO_HPP

#include "empleado.hpp"

using namespace std;

class EmpleadoMedioTiempo: public Empleado {
    private:
        int horasTrabajadas;
        double tarifaPorHora;

    public:
        EmpleadoMedioTiempo(const string &nombre, int id, double tarifaPorHora, int horasTrabajadas);

        void setHorasTrabajadas(int horas); 
        void setTarifaPorHora(double tarifa);

        double getSalario() const override;

        void mostrarInformacion() const override;


};
#endif //EMPLEADO_MEDIO_TIEMPO_HPP