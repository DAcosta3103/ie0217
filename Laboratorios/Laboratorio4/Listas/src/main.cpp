#include "ListaEnlazada.hpp"
#include <iostream>

int main() {
    ListaEnlazada lista;
    int opcion, valor;

    do {
        std::cout << "1. Insertar al inicio\n";
        std::cout << "2. Insertar al final\n";
        std::cout << "3. Eliminar\n";
        std::cout << "4. Imprimir lista\n";
        std::cout << "5. Buscar en la lista\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                lista.insertarInicio(valor);
                break;
            case 2:
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                lista.insertarFinal(valor);
                break;
            case 3:
                std::cout << "Ingrese un valor a eliminar: ";
                std::cin >> valor;
                lista.eliminar(valor);
                break;
            case 4:
                lista.imprimir();
                break;
            case 5:
                std::cout << "Ingrese un valor a buscar: ";
                std::cin >> valor;
                if (lista.buscar(valor)) {
                    std::cout << "Valor encontrado.\n";
                } else {
                    std::cout << "Valor no encontrado.\n";
                }
                break;
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}
