/**
 * @file main.cpp
 * @brief Código main del ejercicio programado de árboles binarios
 * 
 * MIT License

 * Copyright (c) 2024 DAcosta3103
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

    arbol.inicializar();
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
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}