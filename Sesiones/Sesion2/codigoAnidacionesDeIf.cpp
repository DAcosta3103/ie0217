#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    // condicional if externo

    if (num != 0) {

        // condicional if interno/anidado
        if (num > 0) {
         cout << "The number is positive." << endl;
        }

        // condicional else interno/anidado
        else {
        cout << "The number is negative." << endl;
        }
    }

    // condicional else externo
    else {
        cout << "The numer is 0 and it is neither positive nor negative" << endl;
    }

    cout << "This line is always printed." << endl;


    return 0;
}