// En este archivo se brindan tres ejemplos de cómo funciona la herencia al pasar través de varias clases

/*
//--------------------------------------------------------- Ejemplo 1 -------------------------------------------------------------------------------------
// En este ejemplo se muestra una clase A con un método que imprime en pantalla. La clase C hereda de la clase B, la cual hereda de la clase A; y aún así, 
// C puede accesar los métodos de A sin problema


#include <iostream>
using namespace std;

class A {
    public:
        void display() {
            cout << "Base class content"
        }
};

class B: public A;

class C: public B;

int main() {
    C obj;
    obj.display();
    return 0;
}


*/


/*
//--------------------------------------------------------- Ejemplo 2 -------------------------------------------------------------------------------------
// En este ejemplo se muestra una clase heredando de varias clases distintas


#include <iostream>
using namespace std;


// Las siguientes dos clases son individuales la una a la otra

class Mammal {
    public:
        Mammal() {
            cout << "Mammals can give direct birth." << endl;
        }
};

class WingedAnimal {
    public:
        WingedAnimal() {
            cout << "Winged animals can flap." << endl;
        }
};

class Bat: public Mammal, public WingedAnimal {};          // Una clase puede heredar de varias clases

int main() {
    Bat b1;
    return 0;
}


*/


/*
//--------------------------------------------------------- Ejemplo 3 -------------------------------------------------------------------------------------
// En este ejemplo se crean dos clases distintas: Dog & Cat, las cuales ambas heredan de Animal. 
// esto nos dice que una clase puede heredar a más de una clase


#include <iostream>
using namespace std;


class Animal {
    public:
        void Info() {
            cout << "I am an animal." << endl;
        }
};

class Dog: public Animal {
    public:
        void bark() {
            cout << "I am a dog. Woof woof." << endl;
        }
};

class Cat: public Animal {
    public:
        void meow() {
            cout << "I am a cat. Meow." << endl;
        }
};

int main() {
    Dog dog1;
    cout << "Dog Class" << endl;
    dog.info();
    dog.bark();

    cat cat1;
    cout << "Cat Class" << endl;
    cat.info();
    cat.meow();
    
}


*/
