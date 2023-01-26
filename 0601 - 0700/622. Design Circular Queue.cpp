class MyCircularQueue {
private:
    const int k;
    vector<int> q;
    int size = 0;
    int front = 0;
    int rear;

public: 
    // Initialize your data structure here. Set the size of the queue to be k.
    MyCircularQueue(int k) : k(k), q(k), rear(k - 1) {}
    
    // Insert an element into the circular queue. Return true if the operation is successful.
    bool enQueue(int value) {
        if(isFull())
            return 0;
        
        rear = ++rear % k;
        q[rear] = value;
        ++size;
        return true;
    }
    
    // Delete an element from the circular queue. Return true if the operation is successful.
    bool deQueue() {        
        if (isEmpty())
            return false;
        
        front = ++front % k;
        --size;
        return true;
    }
    
    // Get the front item from the queue.
    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    // Get the last item from the queue
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    // Checks whether the circular queue is empty or not.
    bool isEmpty() {
        return size == 0;
    }
    
    // Checks whether the circular queue is full or not.
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
 
 
 
// Time: O(1)
// Space: O(k) 
 




class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
