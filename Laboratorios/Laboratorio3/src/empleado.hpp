#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <iostream>
#include <string>

using namespace std;  

class Empleado {
    protected:
        string nombre;
        int id;
        double salario;

    public:
        // el & de &nombre va a llegar por referencia. Hay 3 maneras de usar parametros: por valor, por referencia o por puntero
        Empleado(const string &nombre, int id, double salario);     // Firmas de las funciones 

        // Creamos el destructor de la clase, y lo hacemos virtual
        virtual ~Empleado() = default;   // El default es para indicarle al compilador que utilice una implementacion que tiene para esto

        void setNombre(const string &nombre);
        string getNombre() const;       // Metodos con 'const' al frente son aqellos que no van a modificar el estado del objeto como tal          
                                        // un metodo con const al frente no altera los objetos de la clase
        
        void setID(int id);
        int getID() const;

        void setSalario(double salario);
        virtual double getSalario() const; 

        friend bool compararSalario(const Empleado &e1, const Empleado &e2);

        friend ostream &operator<<(ostream &os, const Empleado &empleado);       // Seteamos una sobrecarga de operadores para que el compilador sepa cómo interpretar el "<<"

        virtual void mostrarInformacion() const = 0;        // El método virtual igualado a cero se vuelve un método virtual puro: un método sin implementación en la clase base
                                                            // sí o sí tiene que estar en las clases que lo hereden.
        /* Un método virtual puro convierte una clase en una clase abstracta, y yo no puedo crear un objeto a base de esta clase.
        No se puede crear un objeto de una clase abstracta, por lo que la función del método virtual puro es que las funciones derivadas
        siempre tengan que hacer su propia implementación de dicha función.
        */
};   

#endif //  EMPLEADO_HPP