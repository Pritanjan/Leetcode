// APPROACH 1

// Algorithm
// 1. Scan the input string s from left to right and evaluate the expressions based on the 
//    following rules

// 2. If the current character is a digit 0-9 ( operand ), add it to the number currentNumber.

// 3. otherwise the current character must be an operation (+,-,*, /). Evaluate the expression
//    based on the type of operation.

// 4. Addition (+) or Subtraction (-): We must evaluate the expression later based on the next
//    operation. So, we must store the currentNumber to be used later. Let's push the  
//    currentNumber in the Stack.

//    Stack data structure follows Last In First Out (LIFO) principle. Hence, the last pushed 
//    number in the stack would be popped out first for evaluation. In addition, when we pop
//    from the stack and evaluate this expression in the future, we need a way to determine 
//    if the operation was Addition (+) or Subtraction (-). To simplify our evaluation, we can 
//    push -currentNumber in a stack if the current operation is subtraction (-) and assume that
//    the operation for all the values in the stack is addition (+). This works because
//    (a - currentNumber) is equivalent to (a + (-currentNumber)).

// 5. Multiplication (*) or Division (/): Pop the top values from the stack and evaluate the 
//    current expression. Push the evaluated value back to the stack.

// 6. Once the string is scanned, pop from the stack and add to the result.


class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int currNum = 0;
        char op = '+';
        stack<int> stk;

        for(int i=0; i<n; i++){
            char currChar = s[i];
            if(isdigit(currChar)) currNum = (currNum * 10) + (currChar - '0');

            if(!isdigit(currChar) && !iswspace(currChar) || i == n-1){
                if(op == '-') stk.push(-currNum);
                else if(op == '+') stk.push(currNum);
                else if(op == '*'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp * currNum);
                }
                else if(op == '/'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp / currNum);
                }

                op = currChar;
                currNum = 0;
            }
        }

        int res = 0;
        while(stk.size() != 0){
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};

// Complexity Analysis

// Time Complexity : O(n), where n is the length of the string s. 
//                  We iterate over the string sss at most twice.
// Space Complexity: O(n), where n is the length of the string s.




// APPROACH 2

