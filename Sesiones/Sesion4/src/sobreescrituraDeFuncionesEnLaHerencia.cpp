#include <iostream>
using namespace std;

class Base {
    public:
        void print() {
            cout << "Base Function" << endl;

        }
};

class Derived :public Base {
    public:
        void print() {
            cout << "Derived Fucntion" << endl;
        }
};

// Cabe destacar que ambos metodos en ambas clases se llaman igual

int main() {
    Derived derived1, derived2;         // Se instancian ambos objetos
    derived1.print();                   // Se llama al método print en la clase Derived


    // Es posible accesar a la función miembro de la clase Base, solo requiere una sintaxis distinta
    
    derived2.Base::print();             // Con la simbologia de '::'  le decimos de cual clase estamos haciendo sacando el metodo al que hacemos referencia
}
