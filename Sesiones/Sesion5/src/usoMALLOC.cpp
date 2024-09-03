/*  malloc: se utiliza para asignar un bloque de memoria en el heap. Devuelve un puntero void* al inicio de la memoria asignada*/
#include <iostream> 
#include <cstdlib> 
using namespace std;

int main() {

    // allocate memory of int size to an int pointer
    /* Primero se hace un type casting para volver el void* que retorna malloc a un int*. Luego se guarda en esa dirección el tamaño en memoria del entero*/
    int* ptr = (int*) malloc(sizeof(int));      

    // assign the value 5 to allocated memory 
    *ptr = 5;

    cout << *ptr;

    return 0;
}
// Output: 5