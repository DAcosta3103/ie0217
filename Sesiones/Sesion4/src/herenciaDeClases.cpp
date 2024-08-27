#include <iostream>
using namespace std;

class Animal {
    public:
        void eat() {
            cout << "I can eat!" << endl;
        }

         void sleep() {
            cout << "I can sleep!" << endl;
        }
};

class Dog : public Animal {         // La clase Perro viene de la clase animal, por lo que hereda sus metodos.
    public:
        void bark() {
            cout << "I can bark! Woof woof!" << endl;
        }
};

int main() {
    Dog dog1;

    // Llama los miembros de la clase base
    dog1.eat();
    dog1.sleep();


    // Llama miembros de la clase derivada/heredada
    dog1.bark();

    return 0;
}