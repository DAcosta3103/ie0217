#include <iostream>
using namespace std;

// Type Casting se refiere a la accion de transformar una variable de un tipo a otro tipo, como por ejemplo de double a int


// ------------------------------------------------- Conversion de tipo implicita -------------------------------------------------

/*

int main () {

    // se le asigna un valor entero a la variable num_int
    int num_int = 9;

    // se declara una variable tipo doble

    double num_double;

    // conversion implicita
    // se le asigna un valor entero a una variable doble

    num_double = num_int;

    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;

    return 0;
}

*/

// ------------------------------------------------- Conversion de tipo explicita -------------------------------------------------

int main() {

    // declaramos una variable de tipo doble
    double num_double = 3.56;
    cout << "num_double = " << num_double << endl;

    // conversion estilo C de doble a entero
    int num_int1 = (int)num_double;
    cout << "num_int1 = " << num_int1 << endl;

    // conversion estilo C de doble a entero
    int num_int2 = int(num_double);
    cout << "num_int2 = " << num_int2 << endl;

    return 0;
}