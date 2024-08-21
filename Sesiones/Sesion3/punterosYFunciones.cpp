#include <iostream>
using namespace std;


/*
 // Ejemplo1, Paso de parametros de referencia sin punteros

// funcion para cambiar valores
void swap(int &n1, int &n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    // inicializamos las variables
    int a =  1, b = 2;

    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // llamamos a la funcion para cambiar numeros

    swap(a, b);

    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;


}

*/



// Ejemplo 2: paso de parametros por referencia con punteros

// funcion para cambiar valores
void swap(int* n1, int* n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    // inicializamos las variables
    int a =  1, b = 2;

    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // llamamos a la funcion para cambiar numeros

    swap(&a, &b);

    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;


}

// Note que se llega al mismo resultado, pero cuando no usamos punteros manejamos directamente la direccion en memoria de una variable usando &
// y cuando usamos punteros manejamos el valor de la direccion de la variable, el cual esta almacenado en el puntero






