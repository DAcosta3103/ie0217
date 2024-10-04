#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>

using namespace std;

// Prototipos de las dos versiones de quick_sort
template <typename T>
void quick_sort(vector<T>& arr, int low, int high);

template <typename T>
int partition(vector<T>& arr, int low, int high);

// Esta es la versión de quick_sort que toma solo el vector
template <typename T>
void quick_sort(vector<T>& arr) {
    if (!arr.empty()) {
        quick_sort(arr, 0, arr.size() - 1);  // Llamar explícitamente a la versión de tres parámetros
    }
}

// Versión de quick_sort que usa recursión con índices low y high
template <typename T>
void quick_sort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Ordenar los elementos antes y después de la partición
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Elegimos el último elemento como pivote
    int i = (low - 1);   // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Implementación de Bubble Sort como plantilla
template <typename T>
void bubble_sort(vector<T>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Implementación de Selection Sort como plantilla
template <typename T>
void selection_sort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// Implementación de Insertion Sort como plantilla
template <typename T>
void insertion_sort(vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Función para generar un vector de números aleatorios
template <typename T>
vector<T> generate_random_vector(size_t size) {
    if (size <= 0) {
        throw invalid_argument("El tamaño del conjunto de datos debe ser mayor a 0");
    }

    vector<T> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<T> dist(1, 10000);

    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }
    return vec;
}

// Implementación de STL Sort usando sort
template <typename T>
void stl_sort(vector<T>& arr) {
    sort(arr.begin(), arr.end());
}

#endif // SORTING_HPP
