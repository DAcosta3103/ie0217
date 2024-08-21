#include <iostream>
using namespace std;

// imprime un numero en pantalla
void displayNum(int n1, float n2) {
    cout << "The int number is  " << n1;
    cout << "The double number is " << n2;
}

int main () {
    int num1 = 5;
    double num2 = 5.5;

    // llamamos a la funcion
    displayNum(num1, num2);

    return 0;
}
