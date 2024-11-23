#ifndef TREENODE_HPP
#define TREENODE_HPP

// Definición de la estructura de nodo del árbol binario de búsqueda
struct TreeNode {
    int value;        // Valor que almacena el nodo
    TreeNode* left;   // Puntero al hijo izquierdo
    TreeNode* right;  // Puntero al hijo derecho

    // Constructor que inicializa un nodo con un valor específico
    TreeNode(int val);
};

#endif // TREENODE_HPP