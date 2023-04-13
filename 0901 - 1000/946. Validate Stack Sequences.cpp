// APPROACH 1 [ Using a vector to simulate push and pop operations ]

// 1.  iterate over the pushed array, and push each element onto the stack. 
// After each push operation, it checks if the top of the stack matches to the current element of the popped array. 
// 2. If they match, it pops the element from the stack and advances to the next element in the popped array. 
// 3. If they don't match, it continues pushing elements from the pushed array onto the stack



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (auto &x : pushed) {
            stk.push(x);
            while(!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        // return i == popped.size();
        return stk.empty();
    }
};



// time complexity -- O(n), where n is the length of the push and pop arrays, 
// space complexity - O(n), due to the use of a stack.




// APPROACH 2 [ Using two pointers to simulate push and pop operations ]

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(int x : pushed) {
            pushed[i++] = x;
            while(i > 0 && pushed[i-1] == popped[j]) {
                i--;
                j++;
            }
        }
        return i == 0;
    }
};



// Time complexity: O(n)
// because it iterates through the pushed array once, and the inner while loop executes 
// at most n times in total. 
// The outer loop runs n times, and the inner loop runs at most n times in total, 
// so the total number of iterations is O(n).

// Space complexity: O(1)
// because it only uses two integer variables i and j to keep track of the indices
// of the pushed and popped arrays. 
// The pushed and popped arrays are not modified in place, so no extra memory is used.







