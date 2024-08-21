#include <iostream>

using namespace std;

// prototipo funcion

int add(int, int);

int main () {
    int sum;

    //llamamos a la funcion y guardamos el valor retornado en sum
    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;
    return 0;
}

//definicion de la funcion add, ubicada anteriormente en el codigo
int add(int a, int b) {
    return (a + b);
}

// --------------------------------------------------------------   ~  ---------------------------------------------------------------------------------

// A continuacion se vera el caso donde las funciones tienen valores por defecto en sus parametros

/*
//Caso 1: No pasamos ningun argumento

void temp(int = 10, float = 8.8);  // funcion prototipo

int main() {
    ... ...
    temp();
    ... ...
}

void temp(int i, float f) {     // aqui, la funcion tomara por defecto i = 10 y f = 8.8

    // aqui sigue con el codigo que haya

    }

*/

/*
//Caso 2: Solo pasamos el primer argumento

void temp(int = 10, float = 8.8);  // funcion prototipo

int main() {
    ... ...
    temp(6);
    ... ...
}

void temp(int i, float f) {     // aqui, la funcion tomara por i = 6 (valor que le dimos en el main) y f = 8.8 (valor por defecto en la funcion prototipo)

    // aqui sigue con el codigo que haya

    }

*/

/*
//Caso 3: Pasamos ambos argumentos

void temp(int = 10, float = 8.8);  // funcion prototipo

int main() {
    ... ...
    temp(6, -2.3);
    ... ...
}

void temp(int i, float f) {     // aqui, la funcion tomara los valores indicados en el main: i = 6 y f = -2.3

    // aqui sigue con el codigo que haya

    }

*/

/*
//Caso 4 'Error': Pasamos solo el segundo argumento

void temp(int = 10, float = 8.8);  // funcion prototipo

int main() {
    ... ...
    temp(3.4);
    ... ...
}

void temp(int i, float f) {     // aqui, la funcion va a dar un error ya que el compilador lee que i = 3.4, pero i es int

    // no sigue pues hay error
    }

*/

//-------------------------------------------------------------------  Ejemplos  -------------------------------------------------------------------

// Cabe destacar que los valores que vamos a pasar/definir/asignar van primero, y de ultimo los valores que ya estan asignados

/*

// Invalido
void add (int a, int b = 3, int c, int d);   // b deberia ir al final

// Invalido
void add(int a, int b = 3, int c, int d = 4); // d esta bien ubicado pero b deberia ir al final

// Valido
void add(int a, int c, int b = 3, int d = 4); // valores por defecto al final

//Codigo invalido, debido a que no se llama un prototipo de display antes del main

int main() {
    // Llamamos una funcion
    display();
}

void display (char c = '*', int count = 5){
    // codigo
}

*/
