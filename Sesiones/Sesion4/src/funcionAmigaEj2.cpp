#include <iostream>
using namespace std;

class ClassB;       // Declaramos el prototipo de la clase

class ClassA {
    public:
        ClassA() : numA(12) {}          // El constructor de la clase inicializa numA en 12

    private:
        int numA;
        friend int add(ClassA, ClassB);         // Declaramos la funcion amiga

};

class ClassB {
    public:
        ClassB() : numB(1) {}          // El constructor de la clase inicializa numB en 1

    private:
        int numB;                      // Se declara numB
        friend int add(ClassA, ClassB);         // Declaramos la funcion amiga

};

// la funcion amiga puede accesar ambas clases al mismo tiempo, y como es amiga de ambas puede ver sus objetos privados
int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    ClassA objectA;
    ClassB objectB;
    cout << "Sum: " << add(objectA, objectB);
    return 0;
    }
