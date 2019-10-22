// 单链表
#include <stdio.h>

template <class T>
class Link {
public:
    T element;
    Link *next;
    Link(const T item, Link *nextval = NULL) {
        element = item;
        next = nextval;
    }
    Link(Link *nextval = NULL) {
        element = 0;
        next = nextval;
    }
};

template <class T>
class LList : public Link<T> {
public:
    LList() {
        curr = tail = head = new Link<T>;
    }
    ~LList() {
        Link<T> *p = head;
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr; //释放内存
        }
    }
    void append(T item); //链表末尾追加
    T getvalue();        //获取当前位置的data
    void Next();         //移动到后继
    //bool InsertBefore();//当前位置之后插入
    void InsertAfter(T item); //当前位置之前插入
    bool remove();            //删除当前位置之后的元素
    void print();

private:
    Link<T> *head;
    Link<T> *tail;
    Link<T> *curr;
};

template <class T>
void LList<T>::append(T item) {
    Link<T> *p = new Link<T>(item);
    tail->next = p;
    tail = p;
}

template <class T>
T LList<T>::getvalue() {
    return curr->element;
}

template <class T>
void LList<T>::Next() {
    if (curr->next == NULL) {
        return;
    }
    curr = curr->next;
}

template <class T>
void LList<T>::InsertAfter(T item) {
    Link<T> *p = new Link<T>(item, curr->next);
    curr->next = p;
    if (head == tail) //坑
    {
        tail = p;
    }
    return;
}

template <class T>
bool LList<T>::remove() {
    if (curr->next == NULL) {
        return false;
    }
    Link<T> *p = curr->next;
    curr->next = p->next;
    delete p;
    return true;
}

template <class T>
void LList<T>::print() {
    Link<T> *p = head->next;
    while (p->next != NULL) {
        cout << p->element << endl;
        p = p->next;
    }
    cout << p->element << endl;
}
