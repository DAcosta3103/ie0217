/* // Para el mismo ejemplo, primero se crea hace sin usar el manejo de excepciones, lo cual es una mala práctica de programación
   // este ejemplo se ve a continuación
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int numerador, denominador, resultado;

    cout << "Ingrese el numerador: ";
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    resultado = numerador / denominador;
    cout << "El resultado es: " << resultado << endl;

    return 0;
}
 
*/

// Ahora la implementeación correcta, con un código más robusto. Utiliza manejo de excepciones

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int numerador, denominador, resultado;

    cout << "Ingrese el numerador: ";
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        if (denominador == 0) {
            throw runtime_error("Error: el denominador no puede ser cero.");
        }

        resultado = numerador / denominador;
        cout << "El resultado es: " << resultado << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}


