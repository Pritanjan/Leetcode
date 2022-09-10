//https://leetcode.com/problems/implement-stack-using-queues/
//Company Tag Microsoft

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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 

//push() part explation 
// You need to understand how a stack and a queue works. For a stack, it's last-in-first-out, while for a queue, it's first-in-first-out. So if you want to implement a stack using queues, you have to save all elements into an 'auxiliary' queue before pushing new element into the stack. In such way, the newly pushed element will be at the head of queue functioning the same as the top of a stack.
