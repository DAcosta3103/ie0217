/**
 * @file calculadoraEstadisticas.cpp
 * @brief Archivo fuente del script para la claculadora de estadisticas y busqueda en un arreglo.
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
#include <string>
#include <cstdlib> 

using namespace std;

/**
 * @brief Funcion encargada de obtener el arreglo digitado en terminal, el cual esta guardado en argv[]
 * @return void
 */
void obtenerArreglo(int argc, char* argv[], int* arregloAuxiliar) {
    for (int i = 1; i < argc;i++) { 
        arregloAuxiliar[i - 1] = atoi(argv[i]); 
    }
}

/**
 * @brief Funcion para buscar un número en el arreglo
 * @return void
 */
void buscarNumero(int* arregloAuxiliar, int tamanioArreglo) {
    int numeroPorBuscar;
    int* pointerMain = arregloAuxiliar;
    cout << "\nIngrese el numero que desea buscar en el arreglo: ";
    cin >> numeroPorBuscar;
    for (int i = 0; i < tamanioArreglo; i++) {
        if (*pointerMain == numeroPorBuscar) {
            cout << "\nEl numero " << numeroPorBuscar << " efectivamente se encuentra en el arreglo" << endl;
            return;     
        }
        pointerMain++;
    }    
    cout << "\nEl número " << numeroPorBuscar << " no se encuentra en el arreglo." << endl;
}
    
/**
 * @brief Es la encargada de sumar los numeros del arreglo
 * @return La suma total del arreglo
 */
int sumarArreglo(int* arregloAuxiliar, int tamanioArreglo) {
    int* pointerMain = arregloAuxiliar;
    int sumaTotal = 0;

    for (int i = 0; i < tamanioArreglo; i++) {
        sumaTotal += *pointerMain;
        pointerMain++;      
    }
    return sumaTotal;
}

/**
 * @brief Es la encargada de obtener el promedio total del arreglo
 * @return El promedio del arreglo
 */
double promedioArreglo(int* arregloAuxiliar, int tamanioArreglo) {
    int* pointerMain = arregloAuxiliar;
    int sumaTotal = 0;
    int contador = 0;
    for (int i = 0; i < tamanioArreglo; i++) {
        sumaTotal += *pointerMain;
        contador++;
        pointerMain++;
    }
    return sumaTotal/contador;
}

/**
 * @brief Es la encargada de obtener numero mayor del arreglo
 * @return El número más grande del arreglo
 */
int obtenerMayorNum(int* arregloAuxiliar, int tamanioArreglo) {
    int* pointerMain = arregloAuxiliar;
    int mayorNum = 0;
    
    for (int i = 0; i < tamanioArreglo; i++) {
        if (mayorNum < *pointerMain) {
            mayorNum = *pointerMain;
        }
        pointerMain++;
    }
    return mayorNum;
}

/**
 * @brief Es la encargada de obtener numero menor del arreglo
 * @return El número más pequeño del arreglo
 */
int obtenerMenorNum(int* arregloAuxiliar, int tamanioArreglo) {
    int* pointerMain = arregloAuxiliar;
    int menorNum = *pointerMain;
    for (int i = 0; i < tamanioArreglo; i++) {
        if (menorNum > *pointerMain) {
            menorNum = *pointerMain;
        }
        pointerMain++;
    }
    return menorNum;
}

/**
 * @brief Funcion encargada de la logica de la opcion 1
 * @return void
 */
void manejoEstadisticas(int* arregloAuxiliar, int tamanioArreglo) {
    cout << "\nA continuación se tienen las estadísticas del arreglo:\n";
    cout << "La suma total de los números del arreglo es: " << sumarArreglo(arregloAuxiliar, tamanioArreglo) << ".\n";
    cout << "El promedio de los números del arreglo es: " << promedioArreglo(arregloAuxiliar, tamanioArreglo) << ".\n";
    cout << "El número mayor del arreglo es: " << obtenerMayorNum(arregloAuxiliar, tamanioArreglo) << ".\n";
    cout << "El número menor del arreglo es: " << obtenerMenorNum(arregloAuxiliar, tamanioArreglo) << ".\n";
    }



/**
 * @brief Funcion encargada del menu principal. Contiene 3 opciones, las cuales por ahora son placeholder
 * @return void
 */
void menuPrincipal(int* arregloAuxiliar, int tamanioArreglo) {
    int opcion;
    bool opcionValida;

    do {
    cout << "\nMenu principal. Por favor seleccione una opción válida:\n";
    cout << "1. Mostrar estadísticas\n";
    cout << "2. Buscar un número en el arreglo\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
        switch (opcion) {
            case 1: 
            manejoEstadisticas(arregloAuxiliar, tamanioArreglo); 
            opcionValida = true;
            break;

            case 2: 
            buscarNumero(arregloAuxiliar, tamanioArreglo); 
            opcionValida = true;
            break;

            case 3: 
            cout << "\nSaliendo del programa." << endl; 
            opcionValida = true;
            return;

            default: 
            cout << "\nOpción no válida. Intente de nuevo." << endl;
            opcionValida = false;
            break;

        }
    } while (!opcionValida || opcion != 3);  

}
