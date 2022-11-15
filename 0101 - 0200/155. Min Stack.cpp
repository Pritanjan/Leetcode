// https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0

class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st2.push(val);
	    if(st1.empty() || val <= getMin())  
            st1.push(val);	  
    }
    
    void pop() {
	    if(st2.top() == getMin())  
            st1.pop();
	    st2.pop();
    }
    
    int top() {
        return st2.top();
    }
    
    int getMin() {
        return st1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
