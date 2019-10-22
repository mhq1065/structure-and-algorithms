#include <stdio.h>
template <typename T>
class BinaryTreeNode {
private:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

public:
    BinaryTreeNode(const T &data, BinaryTreeNode<T> *left = NULL, BinaryTreeNode *right = NULL)
        : data(data), left(left), right(right){};
    ~BinaryTreeNode(){};
    T value() const;                         //获取data
    BinaryTreeNode<T> *leftchild() const;    //获取左孩子
    BinaryTreeNode<T> *rightchild() const;   //获取右孩子
    void setValue(const T &);                //修改data
    void setLeftchild(BinaryTreeNode<T> *);  //修改左孩子
    void setRightchild(BinaryTreeNode<T> *); //修改右孩子
    bool isLeaf() const;                     //判断是否为叶子节点
    BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node) {
        this = Node;
    };
};

template <typename T>
T BinaryTreeNode<T>::value() const {
    return this->data;
}

template <typename T>
BinaryTreeNode<T> *BinaryTreeNode<T>::leftchild() const {
    return this->left;
}

template <typename T>
BinaryTreeNode<T> *BinaryTreeNode<T>::rightchild() const {
    return this->right;
}

template <typename T>
void BinaryTreeNode<T>::setValue(const T &d) {
    this->data = d;
}

template <typename T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T> *l) {
    this->left = l;
}

template <typename T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T> *r) {
    this->left = r;
}

template <typename T>
bool BinaryTreeNode<T>::isLeaf() const {
    return (left == NULL && right == NULL) ? true : false;
}
