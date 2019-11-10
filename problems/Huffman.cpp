// 哈夫曼树
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class HuffmanTree;

template <typename T>
class HuffmanTreeNode {
    friend class HuffmanTree<T>;

private:
    HuffmanTreeNode<T> *right, *left;
    int wgt;
    T elem;

public:
    HuffmanTreeNode(const T &ele, int w = 0)
        : right(NULL), left(NULL), wgt(w), elem(ele){};
    HuffmanTreeNode(const HuffmanTreeNode<T> *l)
        : right(l->right), left(l->left), wgt(l->wgt), elem(l->elem){};
    HuffmanTreeNode(HuffmanTreeNode<T> *l, HuffmanTreeNode<T> *r, int w)
        : wgt(w), left(l), right(r), elem(T(0)){};
    void setLeft(HuffmanTreeNode<T> *l) { this->left = l; };
    void setRight(HuffmanTreeNode<T> *r) { this->right = r; };
    HuffmanTreeNode<T> *getLeft() { return left; };
    HuffmanTreeNode<T> *getRight() { return right; };
    T &element() { return elem; };
    int weight() { return wgt; };
    bool isLeaf() { return !left && !right; };
};
template <typename T>
class HuffmanTree {
    HuffmanTreeNode<T> *root;

public:
    HuffmanTree() : root(NULL){};
    //HuffmanTree(HuffmanTreeNode<T>* root) : root(root) {};
    HuffmanTree(T ele, int w) {
        root = new HuffmanTreeNode<T>(ele, w);
    }
    HuffmanTree(HuffmanTree<T> *l, HuffmanTree<T> *r, int w) {
        root = new HuffmanTreeNode<T>(l->Root(), r->Root(), w);
    };
    ~HuffmanTree(){};
    HuffmanTreeNode<T> *Root() { return root; };
    int weight() { return root->weight(); };
};
template <typename T>
class cmp {
public:
    bool operator()(HuffmanTree<T> *x, HuffmanTree<T> *y) {
        return x->weight() > y->weight();
    }
};

template <typename T>
HuffmanTree<T> *BuildHuffTree(T element[], int weight[], int n) {
    priority_queue<HuffmanTree<T> *, vector<HuffmanTree<T> *>, cmp<T>> QHTree;
    for (int i = 0; i < n; i++) {
        QHTree.push(new HuffmanTree<T>(element[i], weight[i]));
    }
    while (QHTree.size() > 1) {
        HuffmanTree<T> *rc = QHTree.top();
        QHTree.pop();
        HuffmanTree<T> *lc = QHTree.top();
        QHTree.pop();
        HuffmanTree<T> *parent = new HuffmanTree<T>(lc, rc, lc->weight() + rc->weight());
        QHTree.push(parent);
    }
    return QHTree.top();
}

struct codes {
    bool code[8];
    int length;
};
template <typename T>
void HuffmanCode(HuffmanTreeNode<T> *p, codes s) {
    if (p->isLeaf()) {
        cout << p->element() << '\t';
        for (int i = 0; i < s.length; i++) {
            cout << s.code[i];
        }
        cout << endl;
        return;
    }
    struct codes r = s;
    struct codes l = s;

    r.code[r.length++] = 1;
    l.length++;

    HuffmanCode(p->getLeft(), l);
    HuffmanCode(p->getRight(), r);
}
struct codes c = {
    {0, 0, 0, 0, 0, 0, 0}, 0};
int main() {
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int w[] = {110, 32, 20, 24, 32, 40};
    HuffmanTree<char> *p = BuildHuffTree<char>(a, w, 6);
    HuffmanCode<char>(p->Root(), c);

    return 0;
}
