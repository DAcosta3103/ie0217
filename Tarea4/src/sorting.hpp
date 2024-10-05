/**
 * @file sorting.hpp
 * @brief Headerfile para los algoritmos de ordenamiento
 * 
 * También se declaran los templates dentro de este archivo para evitar pulgas en el script
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
#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>

using namespace std;


/**
 * @brief Prototipo para la función de quick sort 
 * Esta función tiene recursividad con índices low y high
 *  
 * @tparam T 
 * @param arr Vector a utilizar
 * @param low Índice para dato menor
 * @param high Índice para dayo mayor
 */
template <typename T>
void quick_sort(vector<T>& arr, int low, int high);

/**
 * @brief Prototipo auxiliar que elige el pivote para manejar la lógica del algoritmo
 *  
 * @tparam T 
 * @param arr Vector a utilizar
 * @param low Índice para dato menor
 * @param high Índice para dayo mayor
 */
template <typename T>
int partition(vector<T>& arr, int low, int high);

/**
 * @brief Versión de la función Quick Sort que llama a la función quick sort que maneja la lógica
 * 
 * @tparam T 
 * @param arr 
 */
template <typename T>
void quick_sort(vector<T>& arr) {
    if (!arr.empty()) {
        quick_sort(arr, 0, arr.size() - 1);  // Llamar explícitamente a la versión de tres parámetros
    }
}
/**
 * @brief Función para manejar la lógica recursiva del quick sort
 * 
 * @tparam T 
 * @param arr Vector a utilizar
 * @param low Índice para dato menor
 * @param high Índice para dayo mayor
 */
template <typename T>
void quick_sort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Ordenar los elementos antes y después de la partición
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * @brief Funci[on para elegir el pivote para manejar la lógica del algoritmo quick sort
 *  
 * @tparam T 
 * @param arr Vector a utilizar
 * @param low Índice para dato menor
 * @param high Índice para dayo mayor
 * @return int Pivote
 */
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

/**
 * @brief Implementación del algoritmo bubble sort como template
 * 
 * @tparam T 
 * @param arr 
 */
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

/**
 * @brief Implementación del algoritmo selection sort como template
 * 
 * @tparam T 
 * @param arr 
 */
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

/**
 * @brief Implementación del algoritmo insertion sort como template
 * 
 * @tparam T 
 * @param arr 
 */
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

/**
 * @brief Función para generar números aleatorios
 * 
 * @tparam T 
 * @param size 
 * @return vector<T> Un vector con números aleatorios
 */
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


/**
 * @brief Implementación de la función sort del STL como template
 * 
 * @tparam T 
 * @param arr 
 */
template <typename T>
void stl_sort(vector<T>& arr) {
    sort(arr.begin(), arr.end());
}

#endif // SORTING_HPP
