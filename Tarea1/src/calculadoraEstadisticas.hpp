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



// class Estadisticas {
//     public:
//         int numero1, numero2; // Atributos de la funcion
// 
//         Estadisticas(int n1, int n2);
//         
//         // Volvemos al metodo realizarOperacion, el cual sera el encargado de las operaciones matematicas
//         virtual void realizarOperacion(int n1, int n2);
// };
// 
// // Clase para la suma total
// class Suma: public Estadisticas {
//     public:
//         Suma(int n1, int n2);
// 
// 
//         Suma operator+ (const Suma &s);
// 
//         void realizarOperacion()
// 
// }

void obtenerArreglo();
int sumaArreglo();
int promedioArreglo();
int maxArreglo();
int minArreglo();

void buscarNumero();

void menuPrincipal();







#endif  //CALCULADORA_Y_BUSQUEDA_H_ 