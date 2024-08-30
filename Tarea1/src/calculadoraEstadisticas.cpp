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


using namespace std;

/**
 * Se declaran variables globales que serán usadas por varias funciones
 * El arregloNumeros es el arreglo auxiliar donde se ingresarán los números que se obtuvieron de la consola
 * El pointerMain es el puntero encargado de dicho arreglo
 */
int tamanioArreglo;
int arregloNumeros[argc-1];
int* pointerMain = arregloNumeros;


/**
 * @brief Funcion encargada de obtener el arreglo digitado en terminal, el cual esta guardado en argv[]
 * @return void
 */
void obtenerArreglo(int argc, char* argv[], int* arregloAuxiliar) {
    // Transferimos los elementos de argv[] al arreglo auxiliar
    for (int i = 1; i < argc; ++i) { // Comenzamos desde i = 1 para omitir el nombre del programa (argv[0])
        arregloAuxiliar[i - 1] = atoi(argv[i]); // Convertimos cada argumento a entero y lo almacenamos en el arreglo auxiliar
    }

}

/**
 * @brief Funcion para buscar un número en el arreglo
 * @return void
 */
void buscarNumero() {
    int numeroPorBuscar;
    cout << "Ingrese el numero que desea buscar en el arreglo: ";
    cin >> numeroPorBuscar;
    // Ya tenemos el numero ingresado por el usuario en la variable numeroPorBuscar
    
    // Ahora recorremos el arreglo
    for (int i = 0; i < tamanioArreglo; i++) {
        if (*pointerMain == numeroPorBuscar) {
            cout << "El numero " << numeroPorBuscar << " efectivamente se encuentra en el arreglo" << endl;
            return;     // Salimos del for y terminamos la función
        }
        // Si no entramos al if, entonces solo aumentamos de iteracion y seguimos buscando
        pointerMain = pointerMain + i;
        i++;

    }

    // Si estamos fuera del for, es porque terminamos de recorrer el arreglo y no encontramos el numero por buscar
    cout << "El número " << numeroPorBuscar << " no se encuentra en el arreglo." << endl;
}
    
/**
 * @brief Es la encargada de sumar los numeros del arreglo
 * @return La suma total del arreglo
 */
int sumarArreglo() {
    int sumaTotal;

    for (int i = 0; i < tamanioArreglo; i++) {
        sumaTotal += *pointerMain;
        pointerMain++;      // Aumentamos en uno el puntero pointerMain, donde arregloNumeros[pointerMain]
        i++;
    }
    return sumaTotal;
}

/**
 * @brief Es la encargada de obtener el promedio total del arreglo
 * @return El promedio del arreglo
 */
int promedioArreglo() {

    int contador, sumaTotal;
    for (int i = 0; i < tamanioArreglo; i++) {
        sumaTotal += *pointerMain;
        contador++;
        pointerMain++;
        i++;
    }
    return sumaTotal/contador;
}

/**
 * @brief Es la encargada de obtener numero mayor del arreglo
 * @return El número más grande del arreglo
 */
int obtenerMayorNum() {
    int mayorNum, temp;
    
    for (int i = 0; i < tamanioArreglo; i++) {
        temp = *pointerMain;
        if (temp >= mayorNum) {
            mayorNum = temp;
        }
        pointerMain++;
        i++;
    }
    return mayorNum;
}

/**
 * @brief Es la encargada de obtener numero menor del arreglo
 * @return El número más pequeño del arreglo
 */
int obtenerMenorNum() {
    int menorNum = *pointerMain;
    for (int i = 0; i < tamanioArreglo; i++) {
        temp = *pointerMain;
        if (temp <= menorNum) {
            menorNum = temp;
        }
        pointerMain++;
        i++;
    }
    return menorNum;
}

/**
 * @brief Funcion encargada de la logica de la opcion 1
 * @return void
 */
void manejoEstadisticas() {
    cout << "A continuación se tienen las estadísticas del arreglo:\n";
    cout << "La suma total de los números del arreglo es: " << sumarArreglo() << ".\n";
    cout << "El promedio de los números del arreglo es: " << promedioArreglo() << ".\n";
    cout << "El número mayor del arreglo es: " << obtenerMayorNum() << ".\n";
    cout << "El número menor del arreglo es: " << obtenerMenorNum() << ".\n";
    }



/**
 * @brief Funcion encargada del menu principal. Contiene 3 opciones, las cuales por ahora son placeholder
 * @return void
 */
void menuPrincipal() {
    int opcion;
    bool opcionValida;

    do {
    cout << "\nMenu principal. Por favor seleccione una opción válida:\n";
    cout << "1. Mostrar estadísticas\n";
    cout << "2. Buscar un número en el arreglo\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    // Manejamos los casos con las opciones correctas
    
        switch (opcion) {
            case 1: 
            manejoEstadisticas(); 
            opcionValida = true;
            break;

            case 2: 
            buscarNumero(); 
            opcionValida = true;
            break;

            case 3: 
            cout << "Saliendo del programa." << endl; 
            opcionValida = true;
            return;

            default: 
            cout << "Opción no válida. Intente de nuevo." << endl;
            opcionValida = false;
            break;

        }
    } while (!opcionValida);  // opcionValida = false solo en el caso donde el usuario ingresa una opción no permitida

}
