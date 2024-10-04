#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random>
#include "sorting.hpp"

using namespace std;

// Función para medir tiempo de ejecución de un algoritmo de ordenamiento
template <typename Func>
long long measure_sort_time(Func sort_function, vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sort_function(data);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

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
