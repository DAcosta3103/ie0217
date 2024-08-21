#include <iostream>
#include "sum.hpp"      // se incluye el header file de la funcion
using namespace std;

int main(){
    int num1 = 5;
    int num2 = 3;
    int result = sum(num1, num2);

    cout << "El resultado de " << num1 << " + " << num2 << " es igual a: " << result << endl;


    return 0;
}