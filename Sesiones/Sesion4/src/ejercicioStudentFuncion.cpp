#include <iostream>
#include "ejercicioStudentFuncion.hpp"    // Incluimos el headerile

using namespace std; 

void calculateAverage(Student s1, Student s2) {
    
    double average = (s1.mark + s2.mark) / 2;

    cout << "Average marks: " << average << endl;
}