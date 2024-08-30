#include "calculadoraEstadisticas.hpp"
#include <iostream>
#include <cmath>


using namespace std;


/**
 * @brief Funcion encargada de obtener el arreglo digitado en terminal, 
 * el cual esta guardado en argv[]
 */
void obtenerArreglo() {

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

/**
 * @brief Funcion para buscar los numeros en el arreglo
 */
void buscarNumero(int argc, char* argv[], int n) {


    int tamanioArreglo = argc - 1;          // El tamaño del arreglo auxiliar donde se guardaran los numeros ingresados
    int arregloNumeros[tamanioArreglo];  // Se crea el arreglo auxiliar 'arregloNumeos'
    int* punteroArreglo = arregloNumeros;   // Se crea un puntero en el inicio del arreglo de números
    int numeroPorBuscar;
    cout << "Ingrese el numero que desea buscar en el arreglo: ";
    cin >> numeroPorBuscar;
    // Ya tenemos el numero ingresado por el usuario en la variable buscarNum
    // Ahora, debemos pasar lo que está en el arreglo argv[] al arreglo auxiliar que creamos


    // Lo que se tenemos ingresado en (argv) lo pasamos a enteros y lo guardamos en el arreglo auxiliar
    for (int i = 1; i < argc; ++i) {
        arregloNumeros[i - 1] = atoi(argv[i]); // Se convierte empezando desde arg[1] ya que ese argumento es el nombre del programa, 
        // pero se gaurda desde i=0 en el arreglo auxilair
    }

    // Ahora recorremos el arreglo
    for (int i = 0; i < tamanioArreglo; i++) {
        if (arregloNumeros[i] == numeroPorBuscar) {
            cout << "El numero " << numeroPorBuscar << " efectivamente se encuentra en el arreglo" << endl;
            return;
        }

    }

    // Si estamos fuera del for, es porque terminamos de recorrer el arreglo y no encontramos el numero por buscar
    cout << "El número " << numeroPorBuscar << " no se encuentra en el arreglo." << endl;
}
    
/**
 * @brief Es la encargada de sumar los numeros del arreglo
 * @return La suma total del arreglo
 */
int sumarArreglo() {
    
}


    // cout << "Números ingresados:" << endl;
    // for (int i = 0; i < size; i++) {
    //     cout << "El número en la dirección " << i << " es " << numeros[i];
    // }
    // cout << endl;
