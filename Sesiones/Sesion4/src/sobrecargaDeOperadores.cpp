// Yo le puedo decir al compilador cómo quiero que interprete cuando utilice un operador para hacer que los objetos de una clase interactúen, 
// como por ejemplo sumar personas en una clase Persona; ¿qué significa?

#include <iostream>
using namespace std;

class Fraccion {
    int numerador, denominador;
    public:
        Fraccion(int n, int d) : numerador(n), denominador (d){}            // Creamos el constructor de la clase
        
        // Yo le indico al compilador qué quiero que pase cuando sumo objetos de la clase 
        Fraccion operator+ (const Fraccion &f){
            Fraccion resultado(numerador * f.denominador + f.numerador * denominador, denominador * f.denominador);
            
            return resultado;
        }


        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }

};

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);

    f1.imprimir();
    f2.imprimir();

    Fraccion f3 = f1 + f2;

    f3.imprimir();

    return 0;
}
