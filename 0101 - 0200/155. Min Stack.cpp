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

class MinStack {
private:
    stack<pair<int, int>> st;
public:
    // Constructor, initialize the stack.
    MinStack() {}

    void push(int val) {
        // If the stack is empty, 
        // push the value as both the element and the minimum.
        if(st.empty()) st.push({val, val});
        else {
            // else, push the new value and 
            // minimum of the current minimum and the new value.
            int minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
    }

    void pop() {
        // Pop the top element from the stack.
        if(!st.empty()) st.pop();
    }

    int top() {
        // Return the top element of the stack.
        if(!st.empty()) return st.top().first;
        return -1; // Stack is empty, return an arbitrary value.
    }

    int getMin() {
        // Return the minimum element stored at the top of the stack.
        if(!st.empty()) return st.top().second;
        return -1; // Stack is empty, return an arbitrary value.
    }
};






// A 3



