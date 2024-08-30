/**
 * @file conversorDeUnidades.cpp
 * @brief Archivo fuente del script para el conversor de unidades de longitud, peso y temperatura. 
 * 
 * Para poder desplegarle al usuario con qué unidades está trabajando, se aplica una sobrecarga de funciones a * tres funciones  
 * 'unidadString' distintas, las cuales reciben parámetros de longitud, peso o temperatura. 
 * La lógica que las funciones conversoras manejan es la siguiente: el usuario elige un valor x, y luego el usuario elige qué unidad quiere * que tenga x.
 * Sin embargo, lo que pasa por debajo (y sobre lo que no se entera el usuario) es que independientemente de la unidad del valor ingresado,
 * el valor se transforma a la unidad base para realizar el cálculo: metro para longitud, gramo para peso y celsius para temperatura.
 * Es a partir de esta unidad base que se realiza el cálculo, y finalmente se pasa la unidad base a la unidad escogida por el usuario
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


#include "conversorDeUnidades.hpp"

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Función para convertir opciones de longitud a su respectivo string 
 * @param op La opción de longitud de tipo OpcionesLongitud.
 * @return El nombre de la unidad de longitud en string.
 */
string unidadString(OpcionesLongitud op) {
    switch(op) {
        case OpcionesLongitud::metro: return "metros";
        case OpcionesLongitud::kilometro: return "kilómetros";
        case OpcionesLongitud::milimetro: return "milímetros";
        case OpcionesLongitud::centimetro: return "centímetros";
        case OpcionesLongitud::milla: return "millas";
        case OpcionesLongitud::pie: return "pies";
        case OpcionesLongitud::pulgada: return "pulgadas";
        default: return "opción desconocida";
    }
}

/**
 * @brief Función para convertir opciones de peso a su respectivo string 
 * @param op La opción de peso de tipo OpcionesPeso.
 * @return El nombre de la unidad de peso en string.
 */

string unidadString(OpcionesPeso op) {
    switch(op) {
        case OpcionesPeso::gramo: return "gramos";
        case OpcionesPeso::kilogramo: return "kilogramos";
        case OpcionesPeso::miligramo: return "miligramos";
        case OpcionesPeso::libra: return "libras";
        case OpcionesPeso::tonelada: return "toneladas";
        case OpcionesPeso::onza: return "onzas";
        default: return "opción desconocida";
    }
}


/**
 * @brief Función para convertir opciones de temperatura a su respectivo string 
 * @param op La opción de temperatura de tipo OpcionesTemperatura.
 * @return El nombre de la unidad de temperatura en string.
 */
string unidadString(OpcionesTemperatura op) {
    switch(op) {
        case OpcionesTemperatura::celsius: return "C°";
        case OpcionesTemperatura::fahrenheit: return "F°";
        case OpcionesTemperatura::kelvin: return "K";
        default: return "opción desconocida";
    }
}

/**
 * @brief Función para calcular conversiones de longitud 
 * @return void
 */
void convertirUnidadesLongitud() {
    int opcion;
    double valor, metros;
    OpcionesLongitud unidadBase, unidadAConvertir;
    bool opcionValida = false;

    cout << "Elija el valor a ser convertido: " << endl;
    cin >> valor;

    do {
        cout << "\nElija el número de opción de la unidad que desea que tenga el valor ingresado:\n";
        cout << "1. Metros\n";
        cout << "2. Kilómetros\n";
        cout << "3. Milímetros\n";
        cout << "4. Centímetros\n";
        cout << "5. Millas\n";
        cout << "6. Pies\n";
        cout << "7. Pulgadas\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadBase = static_cast<OpcionesLongitud>(opcion);     

        
        switch (unidadBase) {
            case OpcionesLongitud::metro:
                metros = valor;
                opcionValida = true;
                break;    
            case OpcionesLongitud::kilometro:
                metros = valor * 1000;
                opcionValida = true; 
                break; 
            case OpcionesLongitud::milimetro:
                metros = valor / 1000;
                opcionValida = true;
                break;
            case OpcionesLongitud::centimetro:
                metros = valor / 100;
                opcionValida = true;
                break;
            case OpcionesLongitud::milla:
                metros = valor * 1609.34;
                opcionValida = true;
                break;
            case OpcionesLongitud::pie:
                metros = valor * 0.3048;
                opcionValida = true;
                break;
            case OpcionesLongitud::pulgada:
                metros = valor * 0.0254;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        } 
    } while (!opcionValida);

    opcionValida = false;

    do {
        cout << "\nAhora, elija el número de opción de la unidad a la cual desea convertir el valor " << metros << " " << unidadString(unidadBase) << endl;
        cout << "1. Metros\n";
        cout << "2. Kilómetros\n";
        cout << "3. Milímetros\n";
        cout << "4. Centímetros\n";
        cout << "5. Millas\n";
        cout << "6. Pies\n";
        cout << "7. Pulgadas\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadAConvertir = static_cast<OpcionesLongitud>(opcion);

        switch (unidadAConvertir) {
            case OpcionesLongitud::metro:
                valor = metros;
                opcionValida = true;
                break;
            case OpcionesLongitud::kilometro:
                valor = metros / 1000;
                opcionValida = true; 
                break; 
            case OpcionesLongitud::milimetro:
                valor = metros * 1000;
                opcionValida = true;
                break;
            case OpcionesLongitud::centimetro:
                valor = metros * 100;
                opcionValida = true;
                break;
            case OpcionesLongitud::milla:
                valor = metros / 1609.34;
                opcionValida = true;
                break;
            case OpcionesLongitud::pie:
                valor = metros / 0.3048;
                opcionValida = true;
                break;
            case OpcionesLongitud::pulgada:
                valor = metros / 0.0254;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        }
    } while (!opcionValida);

    cout << "El valor ingresado se convierte en: " << valor << " " << unidadString(unidadAConvertir) << endl; 

    menuPrincipal();
}

/**
 * @brief Función para calcular conversiones de peso
 * @return void
 */

void convertirUnidadesPeso() {
    int opcion;
    double valor, gramos;
    OpcionesPeso unidadBase, unidadAConvertir;
    bool opcionValida = false;

    cout << "Elija el valor a ser convertido: " << endl;
    cin >> valor;

    do {
        cout << "\nElija el número de opción de la unidad que desea que tenga el valor ingresado:\n";
        cout << "1. Gramos\n";
        cout << "2. Kilogramos\n";
        cout << "3. Miligramos\n";
        cout << "4. Libras\n";
        cout << "5. Toneladas\n";
        cout << "6. Onzas\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadBase = static_cast<OpcionesPeso>(opcion);

        switch (unidadBase) {
            case OpcionesPeso::gramo:
                gramos = valor;
                opcionValida = true;
                break;
            case OpcionesPeso::kilogramo:
                gramos = valor * 1000;
                opcionValida = true;
                break;
            case OpcionesPeso::miligramo:
                gramos = valor / 1000;
                opcionValida = true;
                break;
            case OpcionesPeso::libra:
                gramos = valor * 453.592;
                opcionValida = true;
                break;
            case OpcionesPeso::tonelada:
                gramos = valor * 1e6;
                opcionValida = true;
                break;
            case OpcionesPeso::onza:
                gramos = valor * 28.3495;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        }
    } while (!opcionValida);

    opcionValida = false;   

    do {
        cout << "\nAhora, elija el número de opción de la unidad a la cual desea convertir el valor " << valor << " " << unidadString(unidadBase) << endl;
        cout << "1. Gramos\n";
        cout << "2. Kilogramos\n";
        cout << "3. Miligramos\n";
        cout << "4. Libras\n";
        cout << "5. Toneladas\n";
        cout << "6. Onzas\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadAConvertir = static_cast<OpcionesPeso>(opcion);   

        switch (unidadAConvertir) {
            case OpcionesPeso::gramo:
                valor = gramos;
                opcionValida = true;
                break;
            case OpcionesPeso::kilogramo:
                valor = gramos / 1000;
                opcionValida = true;
                break;
            case OpcionesPeso::miligramo:
                valor = gramos * 1000;
                opcionValida = true;
                break;
            case OpcionesPeso::libra:
                valor = gramos / 453.592;
                opcionValida = true;
                break;
            case OpcionesPeso::tonelada:
                valor = gramos / 1e6;
                opcionValida = true;
                break;
            case OpcionesPeso::onza:
                valor = gramos / 28.3495;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        }
    } while (!opcionValida);

    cout << "El valor ingresado se convierte en: " << valor << " " << unidadString(unidadAConvertir) << endl; 

    menuPrincipal();
}

/**
 * @brief Función para calcular conversiones de temperatura
 * @return void
 */
void convertirUnidadesTemperatura() {
    int opcion;
    double valor, celsius;
    OpcionesTemperatura unidadBase, unidadAConvertir;
    bool opcionValida = false;

    cout << "Elija el valor a ser convertido: " << endl;
    cin >> valor;

    do {
        cout << "\nElija el número de opción de la unidad que desea que tenga el valor ingresado:\n";
        cout << "1. Celsius\n";
        cout << "2. Fahrenheit\n";
        cout << "3. Kelvin\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadBase = static_cast<OpcionesTemperatura>(opcion);

        switch (unidadBase) {
            case OpcionesTemperatura::celsius:
                celsius = valor;
                opcionValida = true;
                break;
            case OpcionesTemperatura::fahrenheit:
                celsius = (valor - 32) * 5/9;
                opcionValida = true;
                break;
            case OpcionesTemperatura::kelvin:
                celsius = valor - 273.15;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        }
    } while (!opcionValida);

    opcionValida = false;

    do {
        cout << "\nAhora, elija el número de opción de la unidad a la cual desea convertir el valor " << celsius << " " << unidadString(unidadBase) << endl;
        cout << "1. Celsius\n";
        cout << "2. Fahrenheit\n";
        cout << "3. Kelvin\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        unidadAConvertir = static_cast<OpcionesTemperatura>(opcion);

        switch (unidadAConvertir) {
            case OpcionesTemperatura::celsius:
                valor = celsius;
                opcionValida = true;
                break;
            case OpcionesTemperatura::fahrenheit:
                valor = (celsius * 9/5) + 32;
                opcionValida = true;
                break;
            case OpcionesTemperatura::kelvin:
                valor = celsius + 273.15;
                opcionValida = true;
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcionValida = false;
                break;
        }
    } while (!opcionValida);

    cout << "El valor ingresado se convierte en: " << valor << " " << unidadString(unidadAConvertir) << endl;

    menuPrincipal();
}

/**
 * @brief Función para mostrar el menú principal, la cual es recursiva ya que luego de cada conversión se abre el menú. 
 * Se crea la función para el menú principal, la cual es recursiva ya que luego de cada conversión se abre el menú
 * 
 * @return void
 */
void menuPrincipal() {
    int opcion;
    bool opcionValida;

    do {
    cout << "\nMenu principal. Por favor seleccione una opción válida:\n";
    cout << "1. Convertir longitud\n";
    cout << "2. Convertir peso\n";
    cout << "3. Convertir temperatura\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    
    
        switch (opcion) {
            case 1: 
            convertirUnidadesLongitud(); 
            opcionValida = true;
            break;

            case 2: 
            convertirUnidadesPeso(); 
            opcionValida = true;
            break;

            case 3: 
            convertirUnidadesTemperatura(); 
            opcionValida = true;
            break;

            case 4: 
            cout << "Saliendo del programa." << endl; 
            opcionValida = true;
            return;

            default: 
            cout << "Opción no válida. Intente de nuevo." << endl;
            opcionValida = false;
            break;

        }
    } while (!opcionValida);  

}

