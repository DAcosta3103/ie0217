// Optimized bubble sort in C++
#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int array[], int size) {

    // loop to access each array element
    for (int step = 0; step < (size - 1); ++step) {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); ++i) {

            // compare two array elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {

                // swapping occurs if elements are not in intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;        // usamos 'swapped' como un flag para verificar cuando terminamos de sortear el arreglo
            }
        }

        // no swapping means the array is already sorted
        // so no need for further comparison
        if (swapped == 0)
            break;
    }
}

// print an array
void printArray(int array[], int size) {

    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {

    int data[] = {-2, 45, 7, 1, -1, 0, 11, -9};

    // find the array's length
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}
