

#include <iostream>
using namespace std;

class Molde {

    // En el publico, se le da atributos a la clase.
    public:
    double largo;
    double ancho; 
    double alto;
    

    // El molde tiene un funcionamiento parecido al de una funcion, y la forma ;nombreDeLaClase()' se llama el contructor de la clase.
    // tambien se puede llamar inicializador.


    Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {
        cout << "Probando si se puede imprimir." << endl;
    }


/*
    // Esta es otra forma de instanciar el constructor, es más común pero menos elegante
    Molde(){
        cout << "Instanciando Molde" << endl; 
        largo = 15;
        ancho = 12;
        alto = 21;
    }
*/      



    // El destructor se encaega de 'dejar todo limpio' 
    ~Molde() {
        cout << "Saludos desde el destructor de la  clase Molde." << endl;
    }





    // La clase puede tener métodos, que sirven como funciones

    double calcularArea(){
        return largo * ancho;
    }

    double calcularVolumen(){
        return largo * ancho * alto;
    }
    // Los métodos pueden recibir argumentos al igual que una función, visto anteriormente.



};

int main(){

    // Instanciamos 'pared', una variable de tipo (clase) Molde
    Molde pared(10.0, 20.0, 35.0);

    cout << "El área es: " << pared.calcularArea() << endl;
    cout << "El vulemn es: " << pared.calcularVolumen() << endl;
    return 0;
}
