// La mejor manera de demostrar recursividad en funciones es mediante el ejemplo del factorial.
// El factorial de n esta dado por n! = n*n-1*n-2*...*3*2*1

#include <iostream>
using namespace std;

int factorial(int);     // prototipo de la funcion factorial, recibe un parametro entero

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}

int factorial(int n) {

    if (n > 1){
        return n * factorial(n-1);
    } else {
        return 1;
    }
}