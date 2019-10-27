#include "../linkStack.h"
#include <algorithm>
#include <iostream>
//简易背包
using namespace std;
const int T = 10;
const int w[6] = {1, 8, 4, 3, 5, 2};
struct Node {
    int data;
    int pos;
};

class stack : public linkStack<Node> {
private:
    int sum;
    int length;

public:
    stack() : sum(0), length(0), linkStack<Node>(){};
    // stack(int i) : sum(i), length(1), linkStack<Node>() { push(i); };
    ~stack(){};
    int getsum() {
        return sum;
    }
    void push(const int &ele, const int &pos) {
        Node temp = {ele, pos};
        linkStackNode<Node> *p = new linkStackNode<Node>(temp, top);
        top = p;
        sum += ele;
        length++;
    };
    Node pop() {
        if (isEmpty()) {
            cout << "链栈已空" << endl;
            exit(0);
        }
        linkStackNode<Node> *p = top;
        Node t = p->getEle();
        sum -= t.data;
        length--;
        top = top->getptr();
        delete p;
        return t;
    };
    void show() {
        linkStackNode<Node> *p = top;
        while (p != NULL) {
            cout << p->getEle().data << " ";
            p = p->getptr();
        }
        cout << endl;
    };
    Node gettop() {
        return top->getEle();
    }
};
//未排序的
void quiz(int t, const int *arry, int end, int start = 0) {
    static stack s;

    if (s.isEmpty() && end == start) {
        cout << "end" << endl;
        return;
    }

    if (s.getsum() == t) {
        s.show();
        s.pop();
        quiz(t, arry, end, start);
    } else if (start == end) {
        int temp = s.pop().pos + 1;
        quiz(t, arry, end, temp);
    } else if (s.getsum() + arry[start] > t) {
        quiz(t, arry, end, ++start);
    } else {
        s.push(arry[start], start);
        quiz(t, arry, end, ++start);
    }
}
//排好序的
void puzzle(int t, const int *arry, int end, int start = 0) {
    static stack s;
    if (s.isEmpty() && end == start) {
        cout << "end" << endl;
        return;
    }
    if (s.getsum() == t) {
        s.show();
        s.pop();
        int temp = s.pop().pos + 1;
        puzzle(t, arry, end, temp);
    } else if (start == end || s.getsum() + arry[start] > t) {
        int temp = s.pop().pos + 1;
        quiz(t, arry, end, temp);
    } else {
        int temp = s.pop().pos + 1;
        puzzle(t, arry, end, temp);
    }
}
int main() {
    quiz(T, w, 6);
    return 0;
}