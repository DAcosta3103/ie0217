/**
 * @file main10Iteraciones.cpp
 * @brief Función main para realizar las 10 ejecuciones del código dentro de una sola ejecución
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
#include <fstream> // Para escribir en un archivo CSV
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
 * Los datos se extraen directamente a un archivo .csv para así graficarlos.
 * 
 * @return int 
 */
int main() {
    try {
        // Abrir archivo CSV para escritura
        ofstream file("raw_benchmark_data_100k.csv");
        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo para escribir resultados.\n";
            return 1;
        }

        // Escribir encabezados en el archivo CSV
        file << "Tamaño,Repetición,Bubble Sort,Selection Sort,Insertion Sort,Quick Sort,STL Sort\n";

        // Tamaños de prueba
        vector<size_t> sizes = {5000, 10000, 50000, 100000};
        const int num_repetitions = 10; // Número de sets diferentes

        // Comparación de tiempos de varios algoritmos de ordenamiento
        for (auto size : sizes) {
            for (int rep = 0; rep < num_repetitions; ++rep) {
                // Generar datos con semilla distinta en cada repetición
                vector<int> data = generate_random_vector<int>(size); 

                // Medir tiempo de Bubble Sort
                vector<int> bubble_data = data;
                long long bubble_time = measure_sort_time(bubble_sort<int>, bubble_data);

                // Medir tiempo de Selection Sort
                vector<int> selection_data = data;
                long long selection_time = measure_sort_time(selection_sort<int>, selection_data);

                // Medir tiempo de Insertion Sort
                vector<int> insertion_data = data;
                long long insertion_time = measure_sort_time(insertion_sort<int>, insertion_data);

                // Medir tiempo de Quick Sort
                vector<int> quick_data = data;
                long long quick_time = measure_sort_time([](vector<int>& arr) { quick_sort(arr); }, quick_data);

                // Medir tiempo de STL Sort
                vector<int> stl_data = data;
                long long stl_time = measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);

                // Escribir los resultados sin promediar en el archivo CSV
                file << size << "," << rep + 1 << "," << bubble_time << "," << selection_time << "," 
                     << insertion_time << "," << quick_time << "," << stl_time << "\n";
            }

            cout << "Resultados escritos para tamaño: " << size << "\n";
        }

        // Cerrar el archivo
        file.close();
        cout << "Datos brutos guardados en raw_benchmark_data.csv.\n";
    } catch (const std::bad_alloc& e) {
        cerr << "Error: No se pudo asignar memoria - " << e.what() << '\n';
    } catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        cerr << "Excepción: " << e.what() << '\n';
    }

    return 0;
}
