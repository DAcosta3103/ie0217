/*

Ejemplo del funcionamiento de la memoria dinámica 
// declare an int pointer 
int* pointVar;

// dynamically allocate memory for an int variable
// apunta el puntero a la dirección del espacio en la memoria dinámica que estmaos reservando
pointVar = new int;

// assign value to the variable memory 
*pointVar = 45;

// print the value stored in memory 
cout << *pointVar; // Output: 45

// deallocate the memory
delete pointVar;

 */


#include <iostream> 

using namespace std;

int main() {

    // declare an int pointer 
    int* pointInt;

    // declare a float pointer 
    float* pointFloat;

    // reserva espacios de la memoria dinámica
    pointInt = new int; 
    pointFloat = new float;

    // assigning value to the memory 
    *pointInt = 45;
    *pointFloat 45.45f;

    cout << *pointInt << endl; 
    cout << *pointFloat << endl;
    // deallocate the memory delete point Int: delete pointFloat:

    return 0;
    
}