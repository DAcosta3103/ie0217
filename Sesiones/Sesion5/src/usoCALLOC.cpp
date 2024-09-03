/* calloc: se utiliza para asignar un bloque de memoria en el heap, inicializándolo en cero.
Devuelve el puntero void* al inicio de la memoria asignada */

#include <cstdlib> 
#include <iostream> 

using namespace std;

int main() {
    int *ptr;
    ptr = (int *)calloc(5, sizeof(int));        // type casteamos ptr a un int*, y le decimos que asigne 5 elementoss de tamaño sizeof(int). 
    // devuelve un void pointer a una dirección o a NULL


    if (!ptr) {
        cout << "Memory Allocation Failed"; 
        exit(1);
    }
    
    cout<<"Initializing values..." << endl << endl;
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1;
    }
    
    cout << "Initialized values" << endl; 
    
    // Imprimimos el contenido de los valores inicializados
    for (int i = 0; i < 5; i++) {
        /* ptr[i] and *(ptr+i) can be used interchangeably */ 
        cout<<*(ptr + i) << endl;
    }

    free(ptr); // se liberan los elementos
    return 0;
}
