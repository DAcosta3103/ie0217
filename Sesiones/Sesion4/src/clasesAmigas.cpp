#include <iostream>
using namespace std;

class ClassB;       // Declaramos el prototipo de la clase

class ClassA {
    private:
        int numA;
        friend class ClassB;         // Declaramos la clase amiga

    public:
        ClassA() : numA(12) {}          // El constructor de la clase inicializa numA en 12


};

class ClassB {
    private:
        int numB;                      // Se declara numB
    
    public:
        ClassB() : numB(1) {}          // El constructor de la clase inicializa numB en 1

        // se crea una funcion miembro de ClassB para sumar numA de ClassA y numB de ClassB
        int add() {
            ClassA objectA;
            return objectA.numA + numB;
        }
};

int main() {
    ClassB objectB;
    cout << "Sum: " << objectB.add();
    return 0;
    }
