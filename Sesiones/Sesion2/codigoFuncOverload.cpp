// Programa para computar un valor absoluto, funciona con int y float
// A continuacion se observan distintas maneras en que se pueden diferenciar las funciones que comparten nombre

#include <iostream>
using namespace std;




/* //Esta es la prueba inicial de sobrecarga de funciones, donde se diferencian por el tipo de parametro

//funcion con parametro float
float absolute(float var) {
    if (var < 0.0)
        var = -var;
    return var;
}

//funcion con parametro int
float absolute(int var) {
    if (var < 0)
        var = -var;
    return var;
}

*/

// Se pueden diferenciar por el numero de parametros

// funcion de doble parametro
void display(int var1, double var2) {
    cout << "Numero entero: " << var1;
    cout << " y el numero doble: " << var2 << endl;
}

// funcion con un solo parametro tipo doble

void display(double var) {
    cout << "El numero doble: " << var << endl;
}

// funcion con un solo parametro tipo entero

void display(int var) {
    cout << "El numero entero: " << var << endl;
}








int main() {

    /* //Esta es la prueba inicial de sobrecarga de funciones, donde se diferencian por el tipo de parametro a pesar de llamarse igual
    
    // Llamamos a la funcioon con parametro tipo int
    cout << "El valor absluto de -5 = " << absolute(-5) << endl;
    
    // Llamamos a la funcioon con parametro tipo float
    cout << "El valor absluto de 5.5 = " << absolute(5.5f) << endl;
    return 0;

    */

       // Esta es la prueba para diferenciar las funciones por medio de numero de parametros
    
    int a = 5;
    double b = 5.5;

    // llama a la funcion con parametro tipo entero
    display(a);

    // llama a la funcion con parametro tipo doble
    display(b);

    // llama a la funcion con 2 parametros
    display(a, b);

    return 0;
}
