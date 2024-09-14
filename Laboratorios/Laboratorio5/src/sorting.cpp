#include "sorting.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random>

using namespace std;

// Implementación de Bubble Sort
void bubble_sort(vector<int>& arr) {
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

// Implementación de Selection Sort
void selection_sort(vector<int>& arr) {
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

// Implementación de Insertion Sort
void insertion_sort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Función para generar un vector de números aleatorios
vector<int> generate_random_vector(size_t size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10000);

    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }
    return vec;
}
