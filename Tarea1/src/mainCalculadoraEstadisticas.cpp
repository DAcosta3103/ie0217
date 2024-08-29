#include "calculadoraEstadisticasConBusquedaEnArreglo.hpp"
#include <iostream>
#include <cmath>


using namespace std;

// Funcion main

int main(int argc, char* argv[]) {

    // Verificar si se han pasado al menos un argumento (además del nombre del programa, el cual cuenta como 1)
    if (argc < 2) {
        cout << "Por favor, ingrese al menos un numero entero para crear el arreglo." << endl;
        return 1;  // Salir del programa con un código de error
    }


    // Obtener el número de argumentos (excluyendo el nombre del programa)
    int tamanioArreglo = argc - 1;
    int arregloNumeros[tamanioArreglo];  // Se crea un arreglo dentro del script para los numeros ingresados
    int* punteroArray; 

    // Convertir los argumentos de cadena a enteros y almacenarlos en el arreglo
    for (int i = 0; i < tamanioArreglo; i++) {
        arregloNumeros[i] = atoi(argv[i + 1]);  // Convertir el argumento i+1 a entero
        // Se usa argv[i+1] porque i comienza en 0, pero argv[0] es el nombre del programa    }


    // Liberar la memoria asignada dinámicamente
    delete[] numeros;

    return 0;
}
}