// A 1 (USING STACK)
// Use a stack that keeps track of current open brackets. 

// 1. Create a stack. 
// 2. Traverse the string, do following for every character
//      If current character is ‘(’ push it to the stack .
//      If character is ‘)’, pop an element.
//      Maintain maximum count during the traversal. 

class Solution {
public:
    int maxDepth(string s) {
        stack<int> stk; 
        int cnt = 0;
        for(auto i : s){
            if(i == '(' ) stk.push(i);
            else if(i == ')' ) {
                if(cnt < stk.size()) cnt = stk.size();
                stk.pop();
            } 
        }
        return cnt ;
    }
};

// Time Complexity: O(N) where n is number of elements in given string. 
// As, we are using a loop to traverse N times so it will cost us O(N) time 
// Auxiliary Space: O(N), as we are using extra space for stack.


// OR


// 1. Intuition is that we iterate through each character of the string and if the character 
//    happens to be open parentheses then we add it to our stack.
// 2. When we add open parentheses to the stack, we also check if the current stack size is 
//    greater than the max or not. Stack size basically depicts the depth.
// 3. If the character happens to be closing parentheses then we can pop the last open parentheses
//    that we added since it completes our parentheses.

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk; 
        int cnt = 0;
        for(auto i : s){
            if(i == '(' ) stk.push(i);
            else if(i == ')' ) stk.pop();

            cnt = max(cnt, (int)stk.size());
        }
        return cnt;
    }
};

// Time Complexity: O(N) where n is number of elements in given string. 
// Auxiliary Space: O(N)






// A 2
// 1. We can avoid using stack since the only character we are dealing with is open and
//    closing parentheses.
// 2. Instead, we can maintain open parentheses and increment whenever open parentheses
//    encounter and decrease when closing parentheses are encountered.

class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int depth = 0;
        for(char c : s) {
            if(c == '(') {
                depth += 1;
                max = max > depth ? max : depth;
            } 
            else if(c == ')') depth -= 1;
        }
        return max;
    }
};

// Time Complexity: O(N) where n is number of elements in given string. 
// Auxiliary Space: O(1)





// A 3

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int currDepth = 0;
        int i = 0;

        while(i < s.length()) {
            if(s[i] == '(') {
                int j = i+1;
                int openCnt = 1;
                while(j < s.length() && openCnt > 0) {
                    if(s[j] == '(') openCnt++;
                    else if(s[j] == ')') openCnt--;
                    j++;
                }
                res = max(res, maxDepth(s.substr(i+1, j-i-2)) + 1); 
                i = j;
            } 
            else i++;
        }
        return res;
    }
};





// A 4

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int curr = 0;
        for(int i=0; i<s.length(); ++i){
            if(s.at(i) == '(') res = max(res, ++curr); 
            if(s.at(i) == ')') curr--;
        }
        return res;
    }
};


