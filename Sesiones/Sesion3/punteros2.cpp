
#include <iostream>
using namespace std;

int main() {
    int var = 5;        
    int* pointVar;      

    pointVar = &var;    // El valor del puntero es la direccion de var, como es de esperar

    cout << "var = " << var << endl;                    // se imprime el valor de var

    cout << "*pointVar = " << *pointVar << endl;        // print *pointVar, es decir el contenido que esta en esta direccion          

    cout << "Changing the value of var to 7:" << endl;

    var = 7;            // cambiamos el valor de var a 7

    cout << "var = " << var << endl;                    // se imprime el valor de var = 7

    cout << "*pointVar = " << *pointVar << endl;        // print *pointVar, es decir el contenido que esta en esta direccion          

    cout << "Changing the value of var to 16:" << endl;

    *pointVar = 16;            // cambiamos el valor de var a 16 al darle la instruccion al script de que cambie el valor de lo que esta en esa direccion

    cout << "var = " << var << endl;                    // se imprime el valor de var

    cout << "*pointVar = " << *pointVar << endl;        // print *pointVar, es decir el contenido que esta en esta direccion          

    return 0;
}

//------------------------------------------------------ Errores comunes -----------------------------------------------------------

/*

// Hay que tener en cuenta que &var es la direccion de la variable 'var' en memoria.
// Si decimos pointVar = &var, entonces *pointVar es el contenido de lo que esta en la direccion &var. el asterisco antes se llama de-referencia.
// Es decir, pointVar = &var;     *pointVar = var;

*/