class MyCircularQueue {
public:
    int capacity, front, size;
    vector<int>q;
    MyCircularQueue(int k) {
        capacity = k;
        front = 0;
        // rear = -1;
        q.resize(capacity);
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        int rear = (front + size)%capacity;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + size)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        int rear = (front + size -1)%capacity;
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
