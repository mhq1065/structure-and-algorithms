#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

int main() {
    BinaryTreeNode<int> b(2);
    cout << b.value() << endl;
    b.setValue(3);
    cout << b.value() << endl;
    cout << b.isLeaf() << endl;
    return 0;
}