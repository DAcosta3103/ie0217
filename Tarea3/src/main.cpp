#include "arbol.hpp"
#include <iostream>

using namespace std;


/**
 * @brief Funcion main
 * 
 * En la funcion main se maneja la lógica para el menú principal
 * 
 * @return 0
 */
int main() {
    ArbolBinario arbol;     // se declara el objeto árbol

    int opcion, valor;

    // se crea el menú principal

    do {
        cout << "1. Insertar un nodo\n";
        cout << "2. Eliminar un nodo\n";
        cout << "3. Imprimir el árbol\n";
        cout << "4. Calcular la altura del árbol\n";
        cout << "5. Verificar si el árbol está balanceado\n";
        cout << "6. Salir del programa\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor del nodo a insertar: ";
                cin >> valor;
                arbol.insertar(valor);
                break;
            case 2:
                cout << "Ingrese el valor del nodo eliminar: ";
                cin >> valor;
                arbol.eliminar(valor);
                break;
            case 3:
                arbol.inOrden();
                break;
            case 4:
                cout << "La altura del árbol es: " << arbol.altura() << endl;
                break;
            case 5:
                if (arbol.estaBalanceado()) {
                    std::cout << "El árbol está balanceado.\n";
                } else {
                    std::cout << "El árbol no está balanceado.\n";
                }
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}