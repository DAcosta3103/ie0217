// Parecido a las estructuras, podemos crear un grupo de cosas de un tipo (en este caso estaciones del año), para luego enumerarlas y asignarles a cada una un numero
// cabe destacar que se le asigna el numero al nombre, es decir, un string termina representado por un int.

#include <iostream>
using namespace std;

enum seasons {
    sping = 34,
    summer = 4,
    autumn = 9,
    winter = 32

};

int main() {
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl;

    return 0;
}