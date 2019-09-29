//顺序栈
#include <iostream>
using namespace std;

template <class T>
class SeqStack {
public:
    SeqStack(int size);
    ~SeqStack();
    bool isEmpty() const;
    bool isFull() const;
    void SeqStackClear(); //清空顺序栈
    int SeqStackLength(); //获取栈长度
    void push(const T &ele);
    T pop();
    T getpop();

private:
    int maxsize;
    T *base;
    int top;
};

template <class T>
SeqStack<T>::SeqStack(int size) {
    maxsize = size;
    base = new T[maxsize];
    top = 0;
}

template <class T>
SeqStack<T>::~SeqStack() {
    delete[] base;
}

template <class T>
bool SeqStack<T>::isEmpty() const {
    if (top == 0) {
        return true;
    }
    return false;
}

template <class T>
bool SeqStack<T>::isFull() const {
    if (top == maxsize) {
        return true;
    }
    return false;
}

template <class T>
void SeqStack<T>::SeqStackClear() {
    top = 0;
}

template <class T>
int SeqStack<T>::SeqStackLength() {
    return this->top;
}

template <class T>
void SeqStack<T>::push(const T &ele) {
    if (isFull()) {
        cout << "栈已满" << endl;
        return;
    }
    base[top++] = ele;
    return;
}

template <class T>
T SeqStack<T>::pop() {
    if (isEmpty()) {
        cout << "栈已空" << endl;
        exit(0);
    }
    return base[--top];
}

template <class T>
T SeqStack<T>::getpop() {
    if (isEmpty()) {
        cout << "栈已空" << endl;
        exit(0);
    } else {
        return base[top - 1];
    }
}

int main() {
    SeqStack<int> test(5);
    cout << test.isEmpty() << endl;
    test.push(3);
    test.push(5);
    test.push(7);
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.getpop() << endl;
    cout << test.isFull() << endl;
    return 0;
}