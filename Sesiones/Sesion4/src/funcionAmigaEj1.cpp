#include <iostream>
using namespace std;

class Distance {
    private:
        int meter;

        // se agrega una función amiga, la cual puede accesar a los objetos privados de la clase
        friend int addFive(Distance);
    public:
        Distance() : meter(0) {}
    
};

int addFive(Distance d) {
    // ahora, ya que 'addFive' es una función amiga, desde esta puedo acceder a los objetos privados de la clase, en este caso 'meter'
    d.meter += 5;
    return d.meter;
}

int main() {
    Distance D;
    cout << "Distance: " << addFive(D);
    return 0; 
}