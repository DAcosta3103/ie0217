// El tipo de variable que se le puede asignar a un puntero tambien puede ser una estructura, no solo tipos nativos (int, double, float, etc.)

#include <iostream>
using namespace std;

/* // Ejemplo 1

struct temp {
    int i;
    float f;
};

int main(){
    temp *ptr;
    return 0;
}

*/



/* // Ejemplo 2

struct Distance {
    int feet;
    float inch;
};

int main() {
    Distance *ptr, d;           // Asignamos el tipo de variable para el puntero y d, que en este caso el tipo de variable es la estructura que creamos: distance

    ptr = &d                    // Le asignamos la direccion de la variable d al puntero ptr

    cout << "Enter feet: ";
    cin >> (*ptr).feet;         // Imprimimos lo que esta almacenado en la direccion ptr, es decir, imprimimos d.feet

    cout << "Enter inch: ";     // Mismo caso, imprimimos d.inch
    cin >> (*ptr).inch;

    cout << "Displaying information. " << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches.";

    return 0
    

}

*/

/* // Ejemplo 3

// Ya que el punto (.) tiene precedencia mas alta que el asterisco (*), es buena practica utilizar el operador flechita (->) en lugar del punto


struct Distance {
    int feet;
    float inch;
};

int main() {
    Distance *ptr, d;           

    ptr = &d                    

    cout << "Enter feet: ";
    cin >> ptr->feet;         

    cout << "Enter inch: ";     
    cin >> ptr->inch;

    cout << "Displaying information. " << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches.";

    return 0
    

}

*/

