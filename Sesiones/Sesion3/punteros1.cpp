// Como su nombre lo indica, los punteros apuntan a una direccion en memoria

#include <iostream>
using namespace std;

int main() {
    int var = 5;        // Se declara una variable var y se le asigna el valor entero de 5

    int* pointVar;      // Declaramos el puntero de la variable var, y el asterisco nos dice que es un puntero tipo entero

    pointVar = &var;    // El valor del puntero es la direccion de var, como es de esperar

    cout << "var = " << var << endl;                    // se imprime el valor de var

    cout << "Address of var (&var) = " << &var << endl;     //se imprime la direccion de var desde la direccion de var (&var), vlaga la redundancia

    cout << "pointVar = " << pointVar << endl;              // se imprime la direccion de var directamente desde el valor de pointVar

    cout << "Content of the address pointed to pointVar (8pointVar) = " << *pointVar << endl;  
    // un asterisco * al frente se lee como 'el contenido de lo que esta en esta direccion de memoria'
    // en este caso, imprime el contenido de lo que se ubica en &var


    return 0;
}