// APPROACH 1 (USING STACK)

class Solution {
public:
    int maxDepth(string s) {
        stack<int> stk; 
        int cnt = 0;
        for(auto i : s){
            if(i == '(' ){
                stk.push(i);
            } 
            else if(i == ')' ) {
                if(cnt < stk.size()) cnt = stk.size();
                stk.pop();
            } 
        }
        return cnt ;
    }
};


A simple solution is to use a stack that keeps track of current open brackets. 

Create a stack. 
Traverse the string, do following for every character
If current character is ‘(’ push it to the stack .
If character is ‘)’, pop an element.
Maintain maximum count during the traversal. 

// APPROACH 2


// APPROACH 3

