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
    // Tamaños de prueba
    vector<size_t> sizes = {5000, 10000, 20000, 30000, 40000, 50000};

    // Comparación de tiempos de varios algoritmos de ordenamiento
    for (auto size : sizes) {
        vector<int> data = generate_random_vector(size);

        // Medir tiempo de Bubble Sort
        vector<int> bubble_data = data;
        long long bubble_time = measure_sort_time(bubble_sort, bubble_data);
        cout << "Bubble Sort - Tamaño: " << size << " - Tiempo: " << bubble_time << " ms\n";

        // Medir tiempo de Selection Sort
        vector<int> selection_data = data;
        long long selection_time = measure_sort_time(selection_sort, selection_data);
        cout << "Selection Sort - Tamaño: " << size << " - Tiempo: " << selection_time << " ms\n";

        // Medir tiempo de Insertion Sort
        vector<int> insertion_data = data;
        long long insertion_time = measure_sort_time(insertion_sort, insertion_data);
        cout << "Insertion Sort - Tamaño: " << size << " - Tiempo: " << insertion_time << " ms\n";

        // Medir tiempo de STL Sort
        vector<int> stl_data = data;
        long long stl_time = measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);
        cout << "STL Sort - Tamaño: " << size << " - Tiempo: " << stl_time << " ms\n";

        cout << "---------------------------------------------\n";
    }

    return 0;
}
