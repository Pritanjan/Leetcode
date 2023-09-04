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

// Time Complexity: O(N),  N is the length of string.
// Auxiliary Space: O(N)






// A 2
// The idea is to maintain an array that stores the length of the 
// longest valid substring ending at that index. 
// We iterate through the array and return the maximum value

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n <= 1) return 0;
 
        // Initialize curMax to zero
        int curMax = 0;
        vector<int> v(n, 0);
    
        // Iterate over the string starting from second index
        for(int i=1; i<n; i++) {
            if(s[i] == ')' && i - v[i-1] - 1 >= 0 && s[i - v[i-1] - 1] == '(') {
                v[i] = v[i-1] + 2 + ((i - v[i-1] - 2 >= 0) ? v[i - v[i-1] - 2] : 0);
                curMax = max(v[i], curMax);
            }
        }
        return curMax;
    }
};

// Time Complexity: O(N), here N is the length of string.
// Auxiliary Space: O(N)






// A 3

// The idea to solve this problem is to traverse the string on and keep track of the count of open parentheses and close parentheses with the help of two counters left and right respectively.
// First, the string is traversed from the left towards the right and for every “(” encountered, the left counter is incremented by 1 and for every “)” the right counter is incremented by 1.
// Whenever the left becomes equal to right, the length of the current valid string is calculated and if it greater than the current longest substring, then value of required longest substring is updated with current string length.
// If the right counter becomes greater than the left counter, then the set of parentheses has become invalid and hence the left and right counters are set to 0.
// After the above process, the string is similarly traversed from right to left and similar procedure is applied

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int left = 0, right = 0, maxlength = 0, t = 2;

        while (t--) {
            left = 0;
            right = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == '(')
                    left++;
                else
                    right++;

                if (left == right) {
                    maxlength = max(maxlength, 2 * left);
                }

                if (t % 2 == 1 && right > left) {
                    left = 0;
                    right = 0;
                }

                if (t % 2 == 0 && left > right) {
                    left = 0;
                    right = 0;
                }
            }

            reverse(s.begin(), s.end());
        }

        return maxlength;
    }
};

// Time Complexity: O(N), here N is the length of string.
// Auxiliary Space: O(1)






// A 4  -  Using Memoization

// Intuition:
// The problem statement is asking for the length of the longest valid parentheses substring. One way to think about this problem is that for every ‘(‘ we encounter, we need a corresponding ‘)’ somewhere else in the string to form a valid parentheses pair. Therefore, a valid substring must start with an ‘(‘ and end with a ‘)’, and any number of valid parentheses pairs can be in between.

// Approach:
// The approach used here is to use a stack to keep track of the indexes of the characters in the input string. When a ‘(‘ character is encountered, its index is pushed onto the stack. When a ‘)’ character is encountered, the top index on the stack is popped. The difference between the current index and the top index on the stack represents the length of a valid substring ending at the current index. If the stack is empty after a ‘)’ is popped, it means that no matching ‘(‘ has been found, so the current index is pushed onto the stack as the new base for future valid substrings. By doing so, the solution keeps track of the potential valid parentheses starts and ends, and makes use of the property that any valid parentheses substring must be closed by an earlier opened one. Finally, the algorithm returns the max length at the end of the loop.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLen = 0;
        vector<int> memo(n, -1);

        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, lonParen(i, s, memo));
        }

        return maxLen;
    }

    int lonParen(int i, string& s, vector<int>& memo) {
        if (i <= 0) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        if (s[i] == '(') {
            memo[i] = 0;
        } else if (s[i] == ')' && s[i - 1] == '(') {
            memo[i] = lonParen(i - 2, s, memo) + 2;
        } else if (s[i] == ')' && s[i - 1] == ')') {
            int len = lonParen(i - 1, s, memo);
            if (i - 1 - len >= 0 && s[i - 1 - len] == '(') {
                memo[i] = len + 2 + lonParen(i - len - 2, s, memo);
            } else {
                memo[i] = 0;
            }
        }

        return memo[i];
    }
};






// Time complexity: O(n),Here, The algorithm has a time complexity of O(n) because it simply iterates the string once.
// Auxiliary Space: O(n),Space complexity is O(n) because it uses a stack to keep track of the indexes of the characters in the input string.

