#include <iostream>

using namespace std;

// declaramos una funcion

int add(int a, int b) {
    return (a+b);
}

int main () {
    int sum;

    //llamamos a la funcion y guardamos el valor retornado en sum
    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;
    return 0;
}