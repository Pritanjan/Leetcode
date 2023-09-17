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
    stack<int> mainStack;
    stack<int> minStack;
public:
    // Constructor, initialize the two stacks.
    MinStack() {}

    void push(int val) {
        // Push the element onto the main stack.
        mainStack.push(val);

        // If the minStack is empty or the new element is smaller or
        // equal to the current minimum, push it onto the minStack as well.
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // Pop the top element from the main stack.
        if(!mainStack.empty()) {
            // If the element being popped is the current minimum, 
            // also pop it from the minStack.
            if(mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        // Return the top element of the main stack.
        if(!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Stack is empty, return an arbitrary value.
    }

    int getMin() {
        // Return the top element of the minStack, 
        // which represents the current minimum.
        if(!minStack.empty()) return minStack.top();
        return -1; // Stack is empty, return an arbitrary value.
    }
};






// A 3


