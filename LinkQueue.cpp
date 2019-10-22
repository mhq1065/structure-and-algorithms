//队列链式储存 无头节点
#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
class LinkQueue;

template <typename T>
class LinkQueueNode {
    friend class LinkQueue<T>;

public:
    LinkQueueNode(const T &data, LinkQueueNode<T> *next = NULL) : data(data), next(next){};

private:
    T data;
    LinkQueueNode<T> *next;
};

template <typename T>
class LinkQueue {
private:
    LinkQueueNode<T> *font;
    LinkQueueNode<T> *rear;

public:
    LinkQueue() : font(NULL), rear(NULL){};
    ~LinkQueue();
    bool isEmpty() const;
    void LinkQueueClear();       //清空列表
    int LinkQueueLength() const; //求长度
    T GetFont();                 //返回列头元素的值
    void InQueue(const T e);
    T OutQueue();
};

template <typename T>
LinkQueue<T>::~LinkQueue() {
    LinkQueueNode<T> *p = font;
    while (p != NULL) {
        font = font->next;
        delete p;
        p = font;
    }
}

template <typename T>
bool LinkQueue<T>::isEmpty() const {
    if (font == NULL && rear == NULL) {
        return true;
    }
    return false;
}

template <typename T>
int LinkQueue<T>::LinkQueueLength() const {
    LinkQueueNode<T> *p = font;
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

template <typename T>
void LinkQueue<T>::InQueue(const T e) {
    LinkQueueNode<T> *p = new LinkQueueNode<T>(e);
    if (!isEmpty()) {
        rear->next = p;
        rear = p;
    } else {
        font = rear = p;
    }
}

template <typename T>
T LinkQueue<T>::GetFont() {
    if (font == NULL) {
        exit(0);
    } else {
        return font->data;
    }
}

template <typename T>
T LinkQueue<T>::OutQueue() {
    if (font == NULL) {
        exit(0);
    } else {
        T d = font->data;
        LinkQueueNode<T> *p = font;
        font = font->next;
        delete p;
        return d;
    }
}

template <typename T>
void LinkQueue<T>::LinkQueueClear() {
    LinkQueueNode<T> *p = font;
    while (p != NULL) {
        font = font->next;
        delete p;
        p = font;
    }
    font = rear = NULL;
    return;
}

int main(){
    LinkQueue<int> l;
    l.InQueue(3);
    l.InQueue(5);
    l.InQueue(6);
    cout << l.OutQueue() << endl;
    cout << l.LinkQueueLength() << endl;
    return 0;
}