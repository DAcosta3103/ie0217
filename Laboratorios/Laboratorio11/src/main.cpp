#include "arbol.hpp"
#include <iostream>

int main() {
    // Crear un nuevo árbol binario de búsqueda
    BinarySearchTree bst;

    // Insertar varios valores para crear la estructura del árbol
    bst.insert(20);  // Raíz
    bst.insert(10);  // Hijo izquierdo de 20
    bst.insert(30);  // Hijo derecho de 20
    bst.insert(5);   // Hijo izquierdo de 10
    bst.insert(15);  // Hijo derecho de 10
    bst.insert(12);  // Hijo izquierdo de 15
    bst.insert(18);  // Hijo derecho de 15

    // Imprimir el árbol en orden (ordenado de menor a mayor)
    std::cout << "Árbol en orden: ";
    bst.printInOrder();

    // Probar la funcionalidad de búsqueda de ancestro común
    try {
        // Primer caso de prueba: encontrar ancestro común de 12 y 18
        int v1 = 12, v2 = 18;
        std::cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
             << bst.findLowestCommonAncestor(v1, v2) << std::endl;

        // Segundo caso de prueba: encontrar ancestro común de 5 y 30
        v1 = 5; v2 = 30;
        std::cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
             << bst.findLowestCommonAncestor(v1, v2) << std::endl;
    } 
    // Capturar y manejar cualquier error que pueda ocurrir
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}