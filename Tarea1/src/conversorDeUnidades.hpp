/**
 * @file conversorDeUnidades.hpp
 * @brief Headerfile del script para el conversor de unidades de longitud, peso y temperatura.
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

#ifndef CONVERSOR_DE_UNIDADES_H_
#define CONVERSOR_DE_UNIDADES_H_

#include <string>
using namespace std;


/**
 * Enumeración y estructura para las opciones de unidades de longitud.
 */
enum struct OpcionesLongitud {
    metro = 1,      /**< OpcionesLongitud value metro. */  
    kilometro,      /**< OpcionesLongitud value kilometro. */
    milimetro,      /**< OpcionesLongitud value milimetro. */  
    centimetro,     /**< OpcionesLongitud value centimetro. */
    milla,          /**< OpcionesLongitud value milla. */
    pie,            /**< OpcionesLongitud value pie. */
    pulgada         /**< OpcionesLongitud value pulgada. */
};


/**
 * Enumeración y estructura para las opciones de unidades de peso
 */

enum struct OpcionesPeso {
    gramo = 1,      /**< OpcionesPeso value gramo. */  
    kilogramo,      /**< OpcionesPeso value kilogramo. */
    miligramo,      /**< OpcionesPeso value miligramo. */
    libra,          /**< OpcionesPeso value libra. */
    tonelada,       /**< OpcionesPeso value tonelada. */
    onza            /**< OpcionesPeso value onza. */
};


/**
 * Enumeración y estructura para las opciones de unidades de tempe
 */
enum struct OpcionesTemperatura {
    celsius = 1,        /**< OpcionesTemperatura value celsius. */
    fahrenheit,         /**< OpcionesTemperatura value fahrenheit. */
    kelvin              /**< OpcionesTemperatura value kelvin. */
};


/**
 * @brief Función para convertir opciones de longitud a su respectivo string 
 * @param op La opción de longitud de tipo OpcionesLongitud.
 * @return El nombre de la unidad de longitud en string.
 */
string unidadString(OpcionesLongitud op); 

/**
 * @brief Función para convertir opciones de peso a su respectivo string 
 * @param op La opción de peso de tipo OpcionesPeso.
 * @return El nombre de la unidad de peso en string.
 */
string unidadString(OpcionesPeso op); 

/**
 * @brief Función para convertir opciones de temperatura a su respectivo string 
 * @param op La opción de temperatura de tipo OpcionesTemperatura.
 * @return El nombre de la unidad de temperatura en string.
 */
string unidadString(OpcionesTemperatura op); 


/**
 * @brief Función para calcular conversiones de longitud 
 * @return void
 */
void convertirUnidadesLongitud(); 

/**
 * @brief Función para calcular conversiones de peso
 * @return void
 */
void convertirUnidadesPeso(); 

/**
 * @brief Función para calcular conversiones de temperatura
 * @return void
 */
void convertirUnidadesTemperatura();

/**
 * @brief Función para mostrar el menú principal
 * @return void
 */
void menuPrincipal();

#endif // CONVERSOR_DE_UNIDADES_H_