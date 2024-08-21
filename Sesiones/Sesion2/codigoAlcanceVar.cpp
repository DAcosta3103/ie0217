#include <iostream>
using namespace std;

void test()
{
    // la variable 'var' es estatica
    static int var = 0;         //  Es estatica debido al 'static' al inicio de la declaracion
    var++;

    cout << var << endl;
}

int main()
{
    test();                     // Llama a la funcion por primera vez, por lo que var = 0 al ser declarada, pero al final de la funcion var = 1
    test();                     // Debido a que var ya esta inicializada, y de hecho su valor es 1, debido a var++ se imprime en terminal que var = 2

    return 0;
}



// ------------------------------------------------------ Variables Externas ----------------------------------------------------------------

// Un script 'a' puede usar una variable, funcion u objeto declarada en un script 'b', siempre y cuando se especifique que esta variable es externa con el operador 'extern'
// veamos el siguiente ejemplo

/* //Programa 1

#include <iostream>                 
int count ;                         // se declara la variable count
extern void write_extern();         // esta funcion es usada por el programa 1, sin embargo, fue declarada en el programa 2

main() {
    count = 5;
    write_extern();
}

//Programa 2

#include <iostream>

extern int count;                  // se usa la variable externa count, declarada en el programa 1

void write_extern(void) {          // se declara la funcion write_extern

    std::cout << "Count is " << cout << std::endl;  
}



*/