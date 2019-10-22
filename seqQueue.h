//循环队列

template <typename T>
class seqQueue {
public:
    seqQueue(int size) {
        maxsize = ++size;
        front = rear = 0;
        queue = new T[maxsize];
    }
    ~seqQueue() {
        delete[] queue;
    }
    bool isEmpty() const;
    bool isFull() const;
    int queueLength() const;
    void inQueue(const T &e);
    T outQueue();

private:
    int front, rear;
    T *queue; //定义数组
    int maxsize;
};

template <typename T>
bool seqQueue<T>::isEmpty() const {
    if (front == rear) {
        return true;
    }
    return false;
}

template <typename T>
bool seqQueue<T>::isFull() const {
    if ((rear + 1) % maxsize == front) {
        return true;
    }
    return false;
}

template <typename T>
int seqQueue<T>::queueLength() const {
    return (rear - front + maxsize) % maxsize;
}

template <typename T>
void seqQueue<T>::inQueue(const T &e) {
    if (!isFull()) {
        queue[rear] = e;
        rear = (rear + 1) % maxsize;
    } else {
        return;
    }
}

template <typename T>
T seqQueue<T>::outQueue() {
    if (isEmpty()) {
        exit(1);
    }
    T temp = queue[front];
    front = (front + 1) % maxsize;
    return temp;
}
