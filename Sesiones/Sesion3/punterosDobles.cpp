#include <iostream>
using namespace std;



int main(){
    int var = 2050;
    int* ptr_var;       // le digo al programa que se prepare porque voy a almacenar un puntero aca

    ptr_var = &var;

    cout << "var: " << var << ", ptr_var: " << ptr_var << endl;

    int** ptr_ptr_var;                                  // Creamos un puntero para el puntero de var
    ptr_ptr_var = &ptr_var;                             // El puntero del puntero (ptr_ptr_var) da la direccion en memoria del puntero original (ptr_var)
    cout << "ptr_ptr_var: " << ptr_ptr_var << endl;     // Imprime la direccion del puntero original (&ptr_var)

    cout << "&ptr_var: " << &ptr_var << endl;           // Tambien imprime la direccion del puntero original

    cout << "&ptr_ptr_var: " << &ptr_ptr_var << endl;   // Imprime la direccion del puntero del puntero

    return 0;
}