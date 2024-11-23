#include "nodo.hpp"

// Constructor: inicializa un nuevo nodo con un valor y establece los hijos como nulos
TreeNode::TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}