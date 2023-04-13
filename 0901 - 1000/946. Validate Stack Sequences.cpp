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







// APPROACH 3 [ RECURSION ]


// It uses helper function f to recursively simulate the push and pop operations on the stack.
// The function takes two indices i and j as input, which represent the current positions 
// in the pushed and popped vectors, respectively.
// The function checks if the top element of the stack matches the next element to be popped,
// and if so, it pops the element from the stack and increments j. 
// If the top element of the stack does not match the next element to be popped,
// the function checks if there are any more elements to be pushed onto the stack, 
// and if so, it pushes the next element onto the stack and increments i. 
// If there are no more elements to be pushed and the top element of the stack does not match 
// the next element to be popped, the function returns false. 
// If the end of the popped vector is reached, the function returns true.



class Solution {
public:
    stack<int> stk;
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        return f(pushed, popped, 0, 0);
    }

    bool f(vector<int>& pushed, vector<int>& popped, int i, int j) {
        
        if(j == popped.size()) return true;

        if(i < pushed.size() && pushed[i] == popped[j]) {
            return f(pushed, popped, i + 1, j + 1);
        }

        if(!stk.empty() && stk.top() == popped[j]) {
            stk.pop();
            return f(pushed, popped, i, j + 1);
        }

        if(i < pushed.size()) {
            stk.push(pushed[i]);
            return f(pushed, popped, i + 1, j);
        }
        return false;
    }
};


// Time complexity --> O(N), where N is the total no of elements in vectors pushed and popped. 
// Because each element is pushed onto or popped from the stack exactly once.

// Space complexity --> O(N), where N is the total no of elements in the input vectors pushed & popped.
// Because the recursive calls consume space on the call stack, and the stack data structure 
// itself can also hold up to N elements in the worst case.
    




    


