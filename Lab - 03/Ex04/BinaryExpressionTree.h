#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

#include "Node.h"
#include <memory>

class BinaryExpressionTree {
private:
    std::unique_ptr<Node> root;  // Nodo raíz del árbol de expresión
public:
    BinaryExpressionTree(std::unique_ptr<Node> rootNode);  // Constructor
    int evaluate();  // Evaluar el árbol completo
};

#endif
