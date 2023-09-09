// A 1 - Counting Open and Close Parentheses

// 1. Initialize a variable count to store the number of opening parentheses, i.e. ‘(‘.
// 2. Add every ‘(‘ to the result if count is greater than 0, i.e. add all ‘(‘ after 
//    the first ‘(‘ of a primitive substring is encountered.
// 3. Add every ‘)’ to the result if count is greater than 0, i.e. add all ‘)’ before 
//    the last ‘)’ of a primitive substring is encountered.
// 4. Finally, print the resultant string obtained.

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int cnt = 0;
        for(char c : S) {
            if(c == '(' && cnt++ > 0) res += c;
            if(c == ')' && cnt-- > 1) res += c;
        }   
        return res;
    }
};

// Time Complexity: O(N) where n is number of elements in given string. 
// As, we are using a loop to traverse N times so it will cost us O(N) time 

// Auxiliary Space: O(N), as we are using extra space for stack.





// A 2 - Use stack

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> stk;  // stack stores paraenthesius 
        for(char c : s) {
            if(c == '(') {
                if(!stk.empty()) res += c;
                stk.push(c);
            } 
            else {
                stk.pop();
                if(!stk.empty()) res += c;
            }
        }
        return res;
    }
};





// A 3 

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        int idx = 0;
        string res = "";
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                cnt--;
                if(cnt == 0) {
                    // We found the matching closing parenthesis
                    res += s.substr(idx + 1, i - idx - 1);
                    idx = i + 1; // Skip the outermost closing parenthesis
                }
            }
        }
        return res;
    }
};


