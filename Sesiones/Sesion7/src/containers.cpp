/* 
Los contenedores almacenan datos y los organizan de una manera específica según sea necesario. Por ejemplo, los vectores almacenan
datos del mismo tipo en orden secuencial. Existen tres tipos
*/

#include <iostream>
#include <vector>
using namespace std;


/* //Contenedor tipo de secuencia
int main() {

    // initialize a vector of int type
    vector<int> numbers = {1, 100, 10, 70, 100};

    // print the vector
    cout << "Numbers are: ";
    for (auto &num: numbers) {
        cout << num << " ";
    }

    return 0;
}
*/

/* // Contenedor tipo asociativo
int main() {

    // initialize a set of int type
    set<int> numbers = {1, 100, 10, 70, 100};

    // print the set
    cout << "Numbers are: ";
    for (auto &num: numbers) {
        cout << num << " ";
    }

    return 0;
}
 */

/*  // Contenedor tipo asociativo desordenado
int main() {

    // initialize an unordered_set of int type
    unordered_set<int> numbers = {1, 100, 10, 70, 100};

    // print the set
    cout << "Numbers are: ";
    for (auto &num: numbers) {
        cout << num << " ";
    }

    return 0;
}
*/