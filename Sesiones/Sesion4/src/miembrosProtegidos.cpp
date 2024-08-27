#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string color;


    protected:
        string type;

    public:
        void run() { cout << "I can run --BASE" << endl;}
        void eat() { cout << "I can eat!" << endl;}
        void sleep() { cout << "I can sleep!" << endl;}
        void setColor(string clr) { color = clr; }
        string getColor() { return color; }
};



// La clase derivada tiene acceso a lo
class Dog : public Animal {
    public:
        void run() {cout << "I can run --DERIVED" << endl;}
        void setType(string tp) {type = tp;}            // Crea una variable type que contiene la asignacion del tipo de perro, desde un objeto protegido de la clase base
        void displayInfo(string c){
            cout << "I am  a " << type << endl;
            cout << "My color is " << c << endl;
        }


        /* void setColor(string clr) { color = clr; } no se podria hacer ya que las clases derivadas no tienen acceso a los elementos privadossss*/
        void bark() { cout << "I can bark! Woof woof!" << endl;}
};

// Por defecto, los objetos no declarados son privados

int main() {
    Dog dog1;
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");


    dog1.bark();
    dog1.setType("Doberman");
    dog1.displayInfo(dog1.getColor());
    return 0;
}