/**
 * @file calculadoraEstadisticas.hpp
 * @brief Headerfile del script para la claculadora de estadisticas y busqueda en un arreglo.
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


#ifndef CALCULADORA_Y_BUSQUEDA_H_
#define CALCULADORA_Y_BUSQUEDA_H_




/**
 * @brief Funcion encargada de obtener el arreglo digitado en terminal, el cual esta guardado en argv[]
 * @param argc Representa el numero de argumentos pasados en la linea de comandos 
 * @param argv Un arreglo que contiene los argumentos pasados en la linea de comandos
 * @param arregloAuxiliar El arreglo donde se ingresaran los numeros del arreglo argv
 * @return void
 */
void obtenerArreglo(int argc, char* argv[], int* arregloAuxiliar);

/**
 * @brief Funcion para buscar un número en el arreglo
 * @return void
 */
void buscarNumero(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Es la encargada de sumar los numeros del arreglo
 * @return La suma total del arreglo
 */
int sumarArreglo(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Es la encargada de obtener el promedio total del arreglo
 * @return El promedio del arreglo
 */
double promedioArreglo(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Es la encargada de obtener el numero mayor del arreglo
 * @return El número más grande del arreglo
 */
int obtenerMayorNum(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Es la encargada de obtener el numero menor del arreglo
 * @return El numero más peqeño del arreglo
 */
int obtenerMenorNum(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Funcion encargada de la logica de la opcion 1
 * @return void
 */
void manejoEstadisticas(int* arregloAuxiliar, int tamanioArreglo);

/**
 * @brief Es la encargada de desplegar el menu en pantalla y manejar esa logica
 * @return void
 */
void menuPrincipal(int* arregloAuxiliar, int tamanioArreglo);







#endif  //CALCULADORA_Y_BUSQUEDA_H_ 