#include "calculadoraEstadisticasConBusquedaEnArreglo.hpp"
#include <iostream>
#include <cmath>


using namespace std;

// Funcion main

int main(int argc, char* argv[]) {

    // Verificar si se han pasado al menos un argumento (además del nombre del programa, el cual cuenta como 1)
    if (argc < 2) {
        cerr << "Por favor, ingrese al menos un numero entero para crear el arreglo." << endl;
        return 1;  // Deja de correr el programa con un código de error
    }


    // Obtener el número de argumentos (excluyendo el nombre del programa)
    int tamanioArreglo = argc - 1;
    int arregloNumeros[tamanioArreglo];  // Se crea un arreglo dentro del script para los numeros ingresados
    int* punteroArreglo = arregloNumeros; 


    // Convertir los argumentos de cadena a enteros y almacenarlos en el arreglo, empezamos en la segunda iteración ya que argv[]
    for (int i = 1; i < argc; i++) {
        arregloNumeros[i] = atoi(argv[i + 1]);  // Se convierte el argumento i+1 a entero
        // Se usa argv[i+1] porque i comienza en 0, pero argv[0] es el nombre del programa    }


    // Se libera la memoria asignada dinámicamente
    delete[] numeros;

    return 0;
}
}