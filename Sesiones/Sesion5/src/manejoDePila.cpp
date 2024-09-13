#include <iostream>

/* Se almacena en el segmento de data. */
int globalVariable = 42;

int main() {
    /* Se almacena en el stack. */
    int stackVariable = 10;

    /* Se almacena en el heap. */
    /* Esta operación me devuelve un espacio para almacenar un entero */
    int* heapVariable = new int(20);

    std::cout << "Valor de globalVariable: " << globalVariable << std::endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std::endl;
    std::cout << "Valor de heapVariable: " << *heapVariable << std::endl;

    /* Liberar la memoria asignada en el heap. */
    delete heapVariable;

    return 0;
}
