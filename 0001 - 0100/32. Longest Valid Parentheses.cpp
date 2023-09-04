// A 1  STACK

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if n == 0) return 0;
        vector<int> v(n);
        stack<int> st;        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()) {
                    v[i] = i - st.top() +1;
                    if(st.top() != 0) v[i] += v[st.top() - 1];
                    st.pop();
                }
            }
        }
        return *max_element(v.begin(),v.end());
    }
};


// OR


class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();
    
        // Create a stack and push -1 as initial index to it.
        stack<int> stk;
        stk.push(-1);
        // Initialize result
        int res = 0;
    
        // Traverse all characters of given string
        for(int i=0; i<n; i++) {
            // If opening bracket, push index of it
            if(str[i] == '(') stk.push(i);
            // If closing bracket, i.e.,str[i] = ')'
            else {
                // Pop the previous opening bracket's index
                if (!stk.empty()) stk.pop();                
                // Check if this length formed with base of current 
                // valid substring is more than max  so far
                if(!stk.empty()) res = max(res, i - stk.top());
                // If stack is empty. push current index as
                // base for next valid substring (if any)
                else stk.push(i);
            }
        }    
        return res;
    }
};






// A 3
