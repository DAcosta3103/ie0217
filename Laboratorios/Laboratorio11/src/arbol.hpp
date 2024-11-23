#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "nodo.hpp"

// Clase que implementa un árbol binario de búsqueda
class BinarySearchTree {
private:
    TreeNode* root;   // Puntero al nodo raíz del árbol
    
    // Métodos privados auxiliares
    TreeNode* insert(TreeNode* node, int value);        // Inserción recursiva de nodos
    TreeNode* findLCA(TreeNode* node, int v1, int v2);  // Búsqueda recursiva del ancestro común
    void inOrderTraversal(TreeNode* node);              // Recorrido en orden del árbol
    bool search(TreeNode* node, int value);             // Búsqueda recursiva de un valor

public:
    // Constructor por defecto
    BinarySearchTree();
    
    // Métodos públicos del árbol
    void insert(int value);                          // Insertar un nuevo valor
    int findLowestCommonAncestor(int v1, int v2);    // Encontrar ancestro común
    void printInOrder();                             // Imprimir árbol en orden
};

#endif // BINARY_SEARCH_TREE_HPP