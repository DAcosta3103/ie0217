/* realloc: se utiliza para cambiar el tamaño de un bloque de memoria previamente asignado con malloc o calloc. Puede redimensionar el bloque existente o
asignar uno nuevo, y devuelve un puntero al nuevo bloque de memoria. */
#include <iostream> 
#include <cstdlib>

using namespace std;

int main() {
    float *ptr, *new_ptr;
    ptr = (float*) malloc(5* sizeof(float)); // se reservan 5 * el tamaño de un flotante
    
    if (ptr == NULL) {
            cout << "Memory Allocation Failed"; 
            exit(1);
    }

    /* Initializing memory block */ 
    for (int i = 0; i < 5; i++) { 
        ptr[i] = 1.5;
    }

    /* reallocating memory */
    new_ptr = (float*) realloc(ptr, 10* sizeof(float)); // ptr es el oriignal asignado al inicio
    if (new_ptr == NULL) {
        cout << "Memory Re-allocation Failed"; 
        exit(1);
    }
    
    /* Initializing re-allocated memory block */ 
    for (int i = 5; i < 10; i++) {
        new_ptr[i] = i * 2.5;
    }

    cout << "Printing Values" << endl;

    for (int i = 0; i < 10; i++) {
        cout << new_ptr[i] <<< endl;
    }
  
    free(new_ptr);  // se libera newpointer
    return 0;

}