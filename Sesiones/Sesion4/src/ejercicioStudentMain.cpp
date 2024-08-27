#include <iostream>
#include "ejercicioStudentFuncion.hpp"    // Incluimos el headerfile de la funcion, el cual tambien llama al headerfile de la clase

using namespace std;

int main() {
    Student student1(88.0), student2(56.0);

    calculateAverage(student1, student2);

    return 0;
}
