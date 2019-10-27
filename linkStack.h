//链栈
#include <iostream>
#include <stdio.h>
using namespace std;
template <typename T>
class linkStack; //必须先声明

template <typename T>
class linkStackNode {
    friend class linkStack<T>;

private:
    T ele;
    linkStackNode<T> *next;

public:
    linkStackNode(const T &element, linkStackNode<T> *p = NULL) : ele(element), next(p){};
    T getEle() const { return ele; };
    linkStackNode<T> *getptr() const { return next; }
};

template <typename T>
class linkStack {
protected:
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
