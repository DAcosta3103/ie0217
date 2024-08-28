#ifndef EMPLEADO_TIEMPO_COMPLETO_HPP
#define EMPLEADO_TIEMPO_COMPLETO_HPP

#include "empleado.hpp"

using namespace std;

class EmpleadoTiempoCompleto: public Empleado {
    private:
        double bonificacion;
        double deduccion;
    
    public:
        EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion);

        void setBonificacion(double bonificacion);
        void setDeduccion(double deduccion);

        double getSalario() const override;         // override va a sobreescribir sobre la funcion base
        void mostrarInformacion() const override;
};

#endif //EMPLEADO_TIEMPO_COMPLETO_HPP