#ifndef PROMEDIO_H
#define PROMEDIO_H

#include "ejercicioStudentClase.hpp"     // Necesitamos que este archivo tenga conocimiento de la clase Student para acepte objetos de parámetros
#include <iostream>
using namespace std;

// Creamos el prototipo de la función, y le damos como parámetros dos estudiantes, s1 y s2 tipo Student
void calculateAverage(Student s1, Student s2);


#endif // PROMEDIO_H