// A 1

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

// T.C.  O(n), where n is the length of the string s. We iterate over the string sss at most twice.
// S.C. : O(n), where n is the length of the string s.






// A 2

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int currNum = 0;
        int lastNum = 0;
        int res = 0;
        char op = '+';

        for(int i=0; i<n; i++) {
            char currChar = s[i];
            if(isdigit(currChar)) currNum = (currNum * 10) + (currChar - '0');
            if(!isdigit(currChar) && !iswspace(currChar) || i == n-1) {
                if(op == '+' || op == '-') {
                    res += lastNum;
                    lastNum = (op == '+') ? currNum : -currNum;
                }
                else if(op == '*') lastNum = lastNum * currNum;
                else if(op == '/') lastNum = lastNum / currNum;

                op = currChar;
                currNum = 0;
            }
        }
        res += lastNum;
        return res;  
    }
};





// A 3

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        vector<int> v;
        int curr = 0;
        char op = '+';

        if(s.empty()) return 0;
        unordered_set<char> operators = {'+', '-', '*', '/'};
        unordered_set<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        for(int i=0; i<s.length(); ++i) {
            char c = s[i];

            if(nums.find(c) != nums.end()) curr = curr * 10 + (c - '0');
            if(operators.find(c) != operators.end() || i == n-1) {
                if(op == '+') v.push_back(curr);
                else if(op == '-') v.push_back(-curr);
                else if(op == '*') v.back() *= curr;
                else if(op == '/') v.back() = v.back() / curr;
                
                curr = 0;
                op = c;
            }
        }

        int res = 0;
        for(int num : v) {
            res += num;
        }
        return res;
    }
};






// A 4

