/**
 * @file main.cpp
 * @brief Función main para realizar una iteración de la ejecución del código
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random>
#include "sorting.hpp"

using namespace std;


/**
 * @brief Función para medir tiempo de ejecución de un algoritmo de ordenamiento
 * 
 * @tparam Func 
 * @param sort_function Función a usar
 * @param data Datos a medir
 * @return long long Tiempo medido
 */
template <typename Func>
long long measure_sort_time(Func sort_function, vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sort_function(data);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

/**
 * @brief Función main
 * 
 * @return int 
 */
int main() {
    try {
        // Tamaños de prueba
        vector<size_t> sizes = {5000, 10000, 50000, 100000, 200000, 500000};
        const int num_repetitions = 10; // Realizar 10 repeticiones para obtener el promedio

        // Comparación de tiempos de varios algoritmos de ordenamiento
        for (auto size : sizes) {
            vector<int> data = generate_random_vector<int>(size);

            // Calcular el promedio de tiempo de Bubble Sort
            long long total_bubble_time = 0;
            for (int i = 0; i < num_repetitions; ++i) {
                vector<int> bubble_data = data;
                total_bubble_time += measure_sort_time(bubble_sort<int>, bubble_data);
            }
            cout << "Bubble Sort - Tamaño: " << size << " - Tiempo promedio: "
                 << total_bubble_time / num_repetitions << " ms\n";

            // Calcular el promedio de tiempo de Selection Sort
            long long total_selection_time = 0;
            for (int i = 0; i < num_repetitions; ++i) {
                vector<int> selection_data = data;
                total_selection_time += measure_sort_time(selection_sort<int>, selection_data);
            }
            cout << "Selection Sort - Tamaño: " << size << " - Tiempo promedio: "
                 << total_selection_time / num_repetitions << " ms\n";

            // Calcular el promedio de tiempo de Insertion Sort
            long long total_insertion_time = 0;
            for (int i = 0; i < num_repetitions; ++i) {
                vector<int> insertion_data = data;
                total_insertion_time += measure_sort_time(insertion_sort<int>, insertion_data);
            }
            cout << "Insertion Sort - Tamaño: " << size << " - Tiempo promedio: "
                 << total_insertion_time / num_repetitions << " ms\n";

            // Calcular el promedio de tiempo de Quick Sort usando lambda
            long long total_quick_time = 0;
            for (int i = 0; i < num_repetitions; ++i) {
                vector<int> quick_data = data;
                total_quick_time += measure_sort_time([](vector<int>& arr) { quick_sort(arr); }, quick_data);
            }
            cout << "Quick Sort - Tamaño: " << size << " - Tiempo promedio: "
                 << total_quick_time / num_repetitions << " ms\n";

            // Calcular el promedio de tiempo de STL Sort
            long long total_stl_time = 0;
            for (int i = 0; i < num_repetitions; ++i) {
                vector<int> stl_data = data;
                total_stl_time += measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);
            }
            cout << "STL Sort - Tamaño: " << size << " - Tiempo promedio: "
                 << total_stl_time / num_repetitions << " ms\n";

            cout << "---------------------------------------------\n";
        }
    } catch (const std::bad_alloc& e) {
        cerr << "Error: No se pudo asignar memoria - " << e.what() << '\n';
    } catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        cerr << "Excepción: " << e.what() << '\n';
    }

    return 0;
}
