//链栈
#include <iostream>
using namespace std;

template <typename T>
class linkStackNode {
private:
    T ele;
    linkStackNode<T> *next;

public:
    template <typename X>
    friend class linkStack;
    linkStackNode(const T &element, linkStackNode<T> *p = NULL) : ele(element), next(p){};
};

template <typename T>
class linkStack {
private:
    linkStackNode<T> *top;

public:
    linkStack() : top(NULL){};
    ~linkStack();
    bool isEmpty() const;
    void SeqStackClear(); //清空顺序栈
    void push(const T &ele);
    T pop();
    T getpop();
};

template <typename T>
linkStack<T>::~linkStack() {
    while (top != NULL) {
        linkStackNode<T> *t = top;
        top = top->next;
        delete t;
    }
}

template <typename T>
bool linkStack<T>::isEmpty() const {
    return top == NULL;
}

template <typename T>
void linkStack<T>::SeqStackClear() {
    linkStackNode<T> *temp = top;
    while (top != NULL) {
        top = top->next;
        delete temp;
    }
}

template <typename T>
void linkStack<T>::push(const T &ele) {
    linkStackNode<T> *p = new linkStackNode<T>(ele, top);
    top = p;
}

template <typename T>
T linkStack<T>::pop() {
    if (isEmpty()) {
        cout << "链栈已空" << endl;
        exit(0);
    }
    linkStackNode<T> *p = top;
    T t = p->ele;
    top = top->next;
    delete p;
    return t;
}

template <typename T>
T linkStack<T>::getpop() {
    return top->ele;
}

int main() {
    linkStack<int> test;
    cout << test.isEmpty() << endl;
    test.push(3);
    test.push(5);
    test.push(7);
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.getpop() << endl;
    return 0;
}