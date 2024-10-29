#include <iostream>
using namespace std;

int main() {
    // Error de sintaxis: falta un punto y coma
    cout << "Iniciando el programa" << endl;

    int divisor = 0;
    // Error de tiempo de ejecución: división por cero
    int resultado = 10 / divisor;

    int arreglo[5] = {1, 2, 3, 4, 5};
    int suma = 0;
    // Error lógico: la condición del bucle debería ser i < 5
    for (int i = 0; i <= 5; ++i) {
        suma += arreglo[i];
    }

    cout << "Suma de los elementos del arreglo: " << suma << endl;

    return 0;
}
