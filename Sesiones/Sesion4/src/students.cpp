#include <iostream>
using namespace std;

class Student {

    public:
        double marks;

        // La clase tiene un constructor 'Student' que recibe como parámetro un valor flotante 'm'.
        Student (double m) {
            marks = m;
        }
};


// Esta función recibe dos parámetros que vienen de una clase

void calculateAverage(Student s1, Student s2) {
    double average = (s1.marks + s2.marks) / 2;

    cout << "Average Marks = " << average << endl;
}

int main() {

    // Instanciamos el valor de student1 y student2 en el main, los cuales son variables de la clase Student
    Student student1(90.0), student2(50.0);

    // Llamamos a la función de calcualr promedio y le pasamos los objetos, los cuales son studen1 y student2
    calculateAverage(student1, student2);

    return 0;
}