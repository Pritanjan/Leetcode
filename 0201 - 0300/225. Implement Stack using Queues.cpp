// A1 - Using 1 Queue

// In this approach, we maintain a single queue. 
// When pushing an element, we enqueue it to the back of the queue and
// then rotate the queue so that the newly pushed element becomes the front. 
// This way, we maintain the LIFO order.

class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    // push the element x into queue 
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size() - 1 ; i++){
            q.push(q.front());
            q.pop();
        }        
    }
    
    // removes the element from the top of the stack
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    // Get the top element
    int top() {
        return q.front();
    }
    
    // Return whether the stack the empty
    bool empty() {
        return q.empty();
    }
};

//push() part explation 
// You need to understand how a stack and a queue works. 
// For a stack, it's last-in-first-out, while for a queue, it's first-in-first-out. 
// So if you want to implement a stack using queues, you have to save all elements 
// into an 'auxiliary' queue before pushing new element into the stack. 
// In such way, the newly pushed element will be at the head of queue functioning the same
// as the top of a stack.






// A 2 - Using 2 Queue

// In this approach, we maintain two queues: que1 and que2. 
// When pushing an element, we enqueue it to que1. 
// When popping an element or getting the top element, we transfer all elements except the last
// one from que1 to que2. 
// The last element in que1 becomes the top element or the popped element. 
// After that, we swap the names of queue1 and queue2.

class MyStack {
private:
    queue<int> que1, que2;
public:
    void push(int x) {
        que1.push(x);
    }

    int pop() {
        while(que1.size() > 1) {
            que2.push(que1.front());
            que1.pop();
        }
        int tmp = que1.front();
        que1.pop();
        swap(que1, que2);
        return tmp;
    }

    int top() {
        while(que1.size() > 1) {
            que2.push(que1.front());
            que1.pop();
        }
        int tmp = que1.front();
        que2.push(tmp);
        que1.pop();
        swap(que1, que2);
        return tmp;
    }

    bool empty() {
        return que1.empty() && que2.empty();
    }
};


// OR


// In this approach, we maintain two queues: que1 and que2. 
// When pushing an element, we enqueue it to the que2, then transfer all elements from que1 to que2,
// and finally, swap the names of the two queues. 
// This way, the newly pushed element becomes the front of the que1, maintaining the LIFO order.

// This approach doesn't require as much swapping as the A2 a, 
// which makes it slightly more efficient in terms of time complexity. 
// It maintains the LIFO order by transferring elements between the two queues when pushing, 
// effectively reversing their order.

class MyStack {
private:
    queue<int> que1, que2;
public:
    void push(int x) {
        que2.push(x);
        while(!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1, que2);
    }

    int pop() {
        int tmp = que1.front();
        que1.pop();
        return tmp;
    }

    int top() {
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};






// A 3 - Using One Queue with Modified Push

// In this approach, we maintain a single queue and use a modified "push" operation. 
// When pushing an element, we first enqueue all existing elements in the queue, 
// and then enqueue the new element. 
// This effectively places the newly pushed element at the back of the queue.
// To maintain the LIFO order, we can use a temporary queue to reverse the order of elements.

class MyStack {
private:
    queue<int> que;
public:
    void push(int x) {
        queue<int> que1;
        while (!que.empty()) {
            que1.push(que.front());
            que.pop();
        }
        que.push(x);
        
        while(!que1.empty()) {
            que.push(que1.front());
            que1.pop();
        }
    }

    int pop() {
        int poppedElement = que.front();
        que.pop();
        return poppedElement;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
};






// A 4

