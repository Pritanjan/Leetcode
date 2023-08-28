// A1 - Using 1 Queue

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






// A 3 

