// El define sirve para que la compu trabaje una linea en tiempo de precompilacion

#include <iostream>
using namespace std;

#define MI_PRIMER_DEFINE 925


enum seasons {
    sping = 34,
    summer = 4,
    autumn = 9,
    winter = 32

};

enum enumcito {
    carro,
    casa,
    arbol,
    patio

};



int main() {
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl;
    cout << "Define: " << MI_PRIMER_DEFINE << endl;
    cout << "arbol: " << arbol << endl;

    return 0;
}