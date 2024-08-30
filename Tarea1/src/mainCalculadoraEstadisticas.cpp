/**
 * @file mainCalculadoraEstadisticas.cpp
 * @brief Archivo main del script para la claculadora de estadisticas y busqueda en un arreglo.
 * 
 * MIT License

 * Copyright (c) 2024 DAcosta3103
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "calculadoraEstadisticas.hpp"
#include <iostream>




using namespace std;

// Funcion main

int main(int argc, char* argv[]) {

    // Verificar si se han pasado al menos un argumento (además del nombre del programa, el cual cuenta como 1)
    if (argc < 2) {
        cerr << "Por favor, ingrese al menos un numero entero para crear el arreglo." << endl;
        return 1;  // Deja de correr el programa con un código de error
    }


    
    int tamanioArreglo = argc - 1;      // Obtener el número de argumentos (excluyendo el nombre del programa)
    int* arregloNumeros = new int[tamanioArreglo];   // Se crea un arreglo dentro en la memoria para que sea llenado por el script con los numeros ingresados
     

    /**
     * Se llama a la funcion obtenerArreglo, la cual pasa los numeros guardados de argv
     * hacia arregloNumeros
     */
    obtenerArreglo(argc, argv, arregloNumeros); 
    menuPrincipal(arregloNumeros, tamanioArreglo);

    // Se libera la memoria asignada dinámicamente
    delete[] arregloNumeros;

    return 0;
}
