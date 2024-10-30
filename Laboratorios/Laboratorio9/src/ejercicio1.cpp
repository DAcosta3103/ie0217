#include <iostream>  // Biblioteca para operaciones de entrada y salida estándar
#include <vector>    // Biblioteca para el uso de vectores
#include <algorithm> // Biblioteca para funciones de manipulación, como sort

using namespace std;

// Función que calcula la media de un vector de enteros
double calcularMedia(const vector<int>& numeros) {
    double suma = 0; // Variable para almacenar la suma de los elementos del vector

    // Bucle que recorre cada elemento del vector
    for (int i = 0; i < numeros.size(); i++) { // Itera hasta el tamaño del vector (incluyendo un índice fuera del rango)
        suma += numeros[i]; // Agrega el valor del elemento actual a 'suma'
    }

    // Retorna la media dividiendo la suma total entre el número de elementos del vector
    return suma / numeros.size();
}

// Función que calcula la mediana de un vector de enteros
double calcularMediana(vector<int> numeros) {
    // Ordena el vector en orden ascendente
    sort(numeros.begin(), numeros.end());

    int tam = numeros.size(); // Almacena el tamaño del vector en una variable

    // Verifica si el tamaño del vector es par o impar
    if (tam % 2 == 0) {
        // Si es par, la mediana es el promedio de los dos elementos centrales
        return (numeros[tam / 2 - 1] + numeros[tam / 2]) / 2.0;
    } else {
        // Si es impar, la mediana es el elemento central
        return numeros[tam / 2];
    }
}

int main() {
    // Inicializa un vector de enteros con algunos valores
    vector<int> numeros = {1, 4, 8, 110, 33, 49};

    // Llama a la función calcularMedia y almacena el resultado
    double media = calcularMedia(numeros);

    // Llama a la función calcularMediana y almacena el resultado
    double mediana = calcularMediana(numeros);

    // Imprime la media y la mediana en la consola
    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;

    return 0; // Finaliza el programa
}

