// A 1

class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {}
    
    void push(int val) {
        st2.push(val);
    	if(st1.empty() || val <= getMin()) st1.push(val);	  
    }
    
    void pop() {
	if(st2.top() == getMin()) st1.pop();
        st2.pop();
    }
    
    int top() {
        return st2.top();
    }
    
    int getMin() {
        return st1.top();
    }
};





// A 2

