#include "calculadoraEstadisticas.hpp"
#include <iostream>
#include <cmath>


using namespace std;



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
            convertirUnidadesLongitud(); 
            opcionValida = true;
            break;

            case 2: 
            convertirUnidadesPeso(); 
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


void buscarNumero() {

    int buscarNum;
    cout << "Ingrese el numero que desea buscar en el arreglo: ";
    cin >> buscarNum
    // Ya tenemos el numero ingresado por el usuario en la variable buscarNum

    // Ahora recorremos el arreglo
    for (int i = 0; i < tamanioArreglo; i++) {
        if (numeros[i] == buscarNum) {
            cout << "El numero " << buscarNum << " efectivamente se encuentra en el arreglo";
            break;
        } else {
            if (i == tamanioArreglo-1) {
                cout << "El numero " << buscarNum << " no se encuentra en el arreglo";
            }
        }
    }



    // cout << "Números ingresados:" << endl;
    // for (int i = 0; i < size; i++) {
    //     cout << "El número en la dirección " << i << " es " << numeros[i];
    // }
    // cout << endl;

}