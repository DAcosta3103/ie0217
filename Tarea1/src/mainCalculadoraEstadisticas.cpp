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
#include <cstdlib> 





using namespace std;

/**
 * @brief Funcion main, para inicializar el programa, la cual solicita que haya un string de enteros en la linea de comando
 * @param argc Este espacio reservado de C++ almacena el numero de parametros ingresados en la linea de comando, incluyendo el nombre dle programa al inicio
 * @param argv Guarda en un arreglo de caracteres lo que se ingreso en la linea de comandos a la hora de  ejecutar el codigo
 * @return 0
 */
int main(int argc, char* argv[]) {

    
    if (argc < 2) {
        cerr << "Por favor, ingrese al menos un numero entero para crear el arreglo." << endl;
        return 1;  
    }


    
    int tamanioArreglo = argc - 1;      
    int* arregloNumeros = new int[tamanioArreglo];   
     

    /**
     * Se llama a la funcion obtenerArreglo, la cual pasa los numeros guardados de argv
     * hacia arregloNumeros
     * luego se llama al menu
     */
    obtenerArreglo(argc, argv, arregloNumeros); 
    menuPrincipal(arregloNumeros, tamanioArreglo);

    // Se libera la memoria asignada dinámicamente
    delete[] arregloNumeros;

    return 0;
}
