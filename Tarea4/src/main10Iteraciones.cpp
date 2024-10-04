#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random>
#include <fstream> // Para escribir en un archivo CSV
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
        // Abrir archivo CSV para escritura
        ofstream file("benchmark_results.csv");
        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo para escribir resultados.\n";
            return 1;
        }

        // Escribir encabezados en el archivo CSV
        file << "Tamaño,Bubble Sort,Selection Sort,Insertion Sort,Quick Sort,STL Sort\n";

        // Tamaños de prueba
        vector<size_t> sizes = {5000, 10000, 50000};
        const int num_repetitions = 10; // Número de sets diferentes

        // Comparación de tiempos de varios algoritmos de ordenamiento
        for (auto size : sizes) {
            // Promedios para cada algoritmo
            long long total_bubble_time = 0, total_selection_time = 0, total_insertion_time = 0;
            long long total_quick_time = 0, total_stl_time = 0;

            for (int rep = 0; rep < num_repetitions; ++rep) {
                vector<int> data = generate_random_vector<int>(size); // Generar datos con semilla distinta en cada repetición

                // Medir tiempo de Bubble Sort
                vector<int> bubble_data = data;
                total_bubble_time += measure_sort_time(bubble_sort<int>, bubble_data);

                // Medir tiempo de Selection Sort
                vector<int> selection_data = data;
                total_selection_time += measure_sort_time(selection_sort<int>, selection_data);

                // Medir tiempo de Insertion Sort
                vector<int> insertion_data = data;
                total_insertion_time += measure_sort_time(insertion_sort<int>, insertion_data);

                // Medir tiempo de Quick Sort
                vector<int> quick_data = data;
                total_quick_time += measure_sort_time([](vector<int>& arr) { quick_sort(arr); }, quick_data);

                // Medir tiempo de STL Sort
                vector<int> stl_data = data;
                total_stl_time += measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);
            }

            // Calcular los promedios
            long long avg_bubble_time = total_bubble_time / num_repetitions;
            long long avg_selection_time = total_selection_time / num_repetitions;
            long long avg_insertion_time = total_insertion_time / num_repetitions;
            long long avg_quick_time = total_quick_time / num_repetitions;
            long long avg_stl_time = total_stl_time / num_repetitions;

            // Escribir los resultados promediados en el archivo CSV
            file << size << "," << avg_bubble_time << "," << avg_selection_time << "," << avg_insertion_time << "," 
                 << avg_quick_time << "," << avg_stl_time << "\n";

            cout << "Resultados promediados escritos para tamaño: " << size << "\n";
        }

        // Cerrar el archivo
        file.close();
        cout << "Resultados guardados en benchmark_results.csv.\n";
    } catch (const std::bad_alloc& e) {
        cerr << "Error: No se pudo asignar memoria - " << e.what() << '\n';
    } catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        cerr << "Excepción: " << e.what() << '\n';
    }

    return 0;
}
