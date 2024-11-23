#include "arbol.hpp"
#include <iostream>
#include <stdexcept>

// Constructor: inicializa un árbol vacío
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Método recursivo para insertar un valor en el árbol
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    // Si llegamos a un nodo nulo, creamos un nuevo nodo aquí
    if (node == nullptr) {
        return new TreeNode(value);
    }
    
    // Si el valor es menor, insertamos en el subárbol izquierdo
    if (value < node->value) {
        node->left = insert(node->left, value);
    } 
    // Si el valor es mayor, insertamos en el subárbol derecho
    else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    // Si el valor es igual, no hacemos nada (evitamos duplicados)
    return node;
}

// Método recursivo para encontrar el ancestro común más cercano
TreeNode* BinarySearchTree::findLCA(TreeNode* node, int v1, int v2) {
    // Si el nodo es nulo, no hay ancestro común
    if (node == nullptr) {
        return nullptr;
    }
    
    // Si ambos valores son menores, el ancestro está en el subárbol izquierdo
    if (v1 < node->value && v2 < node->value) {
        return findLCA(node->left, v1, v2);
    }
    
    // Si ambos valores son mayores, el ancestro está en el subárbol derecho
    if (v1 > node->value && v2 > node->value) {
        return findLCA(node->right, v1, v2);
    }
    
    // Si los valores están en diferentes subárboles, este es el ancestro común
    return node;
}

// Método recursivo para recorrer el árbol en orden
void BinarySearchTree::inOrderTraversal(TreeNode* node) {
    // Si el nodo es nulo, terminamos esta rama de la recursión
    if (node == nullptr) return;
    
    // Primero visitamos el subárbol izquierdo
    inOrderTraversal(node->left);
    // Luego imprimimos el valor del nodo actual
    std::cout << node->value << " ";
    // Finalmente visitamos el subárbol derecho
    inOrderTraversal(node->right);
}

// Método recursivo para buscar un valor en el árbol
bool BinarySearchTree::search(TreeNode* node, int value) {
    // Si el nodo es nulo, el valor no está en el árbol
    if (node == nullptr) return false;
    // Si encontramos el valor, retornamos verdadero
    if (node->value == value) return true;
    // Si el valor es menor, buscamos en el subárbol izquierdo
    if (value < node->value) return search(node->left, value);
    // Si el valor es mayor, buscamos en el subárbol derecho
    return search(node->right, value);
}

// Método público para insertar un valor en el árbol
void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}

// Método público para encontrar el ancestro común más cercano
int BinarySearchTree::findLowestCommonAncestor(int v1, int v2) {
    // Verificamos que ambos valores existan en el árbol
    if (!search(root, v1) || !search(root, v2)) {
        throw std::invalid_argument("Uno o ambos valores no existen en el árbol.");
    }
    
    // Buscamos el ancestro común
    TreeNode* lca = findLCA(root, v1, v2);
    // Si no se encuentra, lanzamos una excepción
    if (lca == nullptr) {
        throw std::runtime_error("No se encontró el ancestro común.");
    }
    // Retornamos el valor del ancestro común
    return lca->value;
}

// Método público para imprimir el árbol en orden
void BinarySearchTree::printInOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}