#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir tiempo
#include <random>

using namespace std;

void bubble_sort(vector<int>& arr);

void selection_sort(vector<int>& arr);

void insertion_sort(vector<int>& arr);

vector<int> generate_random_vector(size_t size);


#endif // SORTING_HPP