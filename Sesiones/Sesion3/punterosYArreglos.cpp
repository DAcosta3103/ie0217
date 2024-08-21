// Ahora veamos como se comportan los punteros en arreglos
#include <iostream>
using namespace std;

int main() {
    float arreglo[3];   // creamos un arreglo de 3 espacios con entradas tipo flotante

    float *puntero;     // declaramos el puntero
    cout << "Displaying address using arrays: " << endl;

    // usamos un bucle for para imprimir las direcciones de todos los elementos del arreglo
    for (int i = 0; i < 3; i++) {
        cout << "&arreglo[" << i << "] = " << &arreglo[i] << endl;
    }
    // puntero = &arreglo[0]
    puntero = arreglo;
    cout << "\nDisplaying address using pointers: " << endl;

    // usamos un bucle for para imprimir las direcciones de los elementos del arreglo
    // usamos notacion puntero
    
    for (int i = 0; i < 3; i++) {
        cout << "puntero + " << i << " = " << puntero + i << endl;
    }

    return 0;
}