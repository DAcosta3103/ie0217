#include <iostream>
#include <cstring>

using namespace std;


// Cabe destacar que usando estructuras 'struct', podemos ahorrar memoria ya que no hay que declarar 4n variables para n libros, sino que el valor
// de las variables se declara automáticamente en los parámetros del main

/*
struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main() {

    // se declara Book1 y Book2 como tipos de Book
    struct Books Book1;         
    struct Books Book2;

    // especificaciones del Book1
    strcpy( Book1.title, "Learn C++ Programming");
    strcpy( Book1.author, "Chand Miyan");
    strcpy( Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;

    // especificaciones del Book2
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Yakit Singha");
    strcpy( Book2.subject, "Telecom");
    Book2.book_id = 6495700;

    // imprimir en pantalla la info del Book1
    cout << "Book 1 title: " << Book1.title << endl;
    cout << "Book 1 author: " << Book1.author << endl;
    cout << "Book 1 subject: " << Book1.subject << endl;
    cout << "Book 1 id: " << Book1.book_id << endl;


    // imprimir en pantalla la info del Book2
    cout << "Book 2 title: " << Book2.title << endl;
    cout << "Book 2 author: " << Book2.author << endl;
    cout << "Book 2 subject: " << Book2.subject << endl;
    cout << "Book 2 id: " << Book2.book_id << endl;
    
    return 0;
}

*/

//--------------------------------------------------- Ejemplo 2 -----------------------------------------------------
//Para este ejemplo, se le pide al usuario que ingrese los parametros de la estructura, y luego se imprimen en pantalla

struct Person
{
    char name[50];
    int age;
    float salary;
};

int main()
{
    Person p1;          // Declaramos a p1 como una variable de tipo 'Person'


    // Ahora procedemos a pedirle al usuario la informacion para p1
    cout << "Enter full name: ";
    cin.get(p1.name, 50);
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter salary: ";
    cin >> p1.salary;

    // Con la informacion ingresada por el usuario, se procede a imprimir en terminal los datos de p1

    cout << "\nDisplaying information." << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;

    return 0;
}
