#include "ArbolBinarioBusqueda.hpp"
#include <iostream>

int main() {

    
    ArbolBinarioBusqueda arbol; // se crea un objeto arbol de tipo ArbolBinarioBusqueda
    int opcion, valor;

    // se instaura el menú principal, llamando a las funciones respectivamente
    do {
        std::cout << "1. Insertar un nodo\n";
        std::cout << "2. Recorrido en Preorden\n";
        std::cout << "3. Recorrido en Inorden\n";
        std::cout << "4. Recorrido en Postorden\n";
        std::cout << "5. Buscar un valor\n";
        std::cout << "6. Altura del árbol\n";
        std::cout << "7. Verificar si el árbol está balanceado\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                arbol.insertar(valor);
                break;
            case 2:
                arbol.preOrden();
                break;
            case 3:
                arbol.inOrden();
                break;
            case 4:
                arbol.postOrden();
                break;
            case 5:
                std::cout << "Ingrese un valor a buscar: ";
                std::cin >> valor;
                if (arbol.buscar(valor)) {
                    std::cout << "Valor encontrado.\n";
                } else {
                    std::cout << "Valor no encontrado.\n";
                }
                break;
            case 6:
                std::cout << "Altura del árbol: " << arbol.altura() << std::endl;
                break;
            case 7:
                if (arbol.estaBalanceado()) {
                    std::cout << "El árbol está balanceado.\n";
                } else {
                    std::cout << "El árbol no está balanceado.\n";
                }
                break;
            case 8:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 8);

    return 0;
}

