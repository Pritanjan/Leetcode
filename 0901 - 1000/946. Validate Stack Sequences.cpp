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
        return i == popped.size();
    }
};



// time complexity -- O(n), where n is the length of the push and pop arrays, 
// space complexity - O(n), due to the use of a stack.
