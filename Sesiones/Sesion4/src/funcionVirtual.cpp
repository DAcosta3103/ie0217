// Las funciones virtuales son funciones miembro de la clase base que esperamos redefinir en clases derivadas

#include <iostream>
using namespace std;

class Base {
    public:
        virtual void print() {
            cout << "Base function" << endl;
        }
};

class Derived : public Base {
    public:
        void print() {
            cout << "Derived function" << endl;
        }
};

int main () {
    Derived derived1;

    // puntero de tipo Base que apunta a derived1
    Base* base1 = &derived1;

    // llama a funcion miembro de clase derivada
    base1->print();

    return 0;
}