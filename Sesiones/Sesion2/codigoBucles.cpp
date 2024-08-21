#include <iostream>

using namespace std;

int funcFor() {     //Ejemplo del for
        for (int i = 1; i <= 5; i++) {
            cout << i << " ";
        }
        return 0;
    }

int funcWhile() {   //Ejemplo 1 del while
        int num_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        for (int n : num_array) {
            cout << n << " ";
        }
        return 0;
    }


int funcWhile2() {  //Ejemplo 2 de while
        int i = 1;

        // while loop de 1 a 5
        while (i <= 5) {
            cout << i << " ";
            i++;
        }

        return 0;
        
    }


int funcdoWhile() { //Ejemplo del do..While
        int i = 1;

        // loop do..While del 1 al 5
        do {
            cout << i << " ";
            i++;
        }
        while (i <= 5);

        return 0;
        } 


int main() { //Funcion main para probar las funciones

    funcFor();

    }
