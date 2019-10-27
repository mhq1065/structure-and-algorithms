#include "BinaryTreeNode.h"

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> *Node;

public:
    BinaryTree(BinaryTreeNode<T> *n=NULL) { Node = n; };
    ~BinaryTree();
};
