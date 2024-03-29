// APPROACH 1

class Solution {
public:
    int scoreOfParentheses(string S) {
        return F(S, 0, S.length());
    }

    int F(string S, int i, int j) {
        //Score of balanced string S[i:j]
        int cnt = 0, bal = 0;

        // Split string into primitives
        for(int k = i; k < j; ++k) {
            bal += S[k] == '(' ? 1 : -1;
            if(bal == 0) {
                if(k - i == 1) cnt++;
                else cnt += 2 * F(S, i+1, k);
                i = k+1;
            }
        }
        return cnt;
    }
};



// The scoreOfParentheses function simply calls the recursive helper function F with the
// input string S and the range [0, S.length()).

// The F function takes three arguments: 
//   the input string S, and two integer indices i and j 
// that define the range of the balanced string being considered.

// The function starts by initializing two variables: cnt, which represents the score
// of the balanced string, and bal, which keeps track of the balance of parentheses 
// as the function iterates through the string.

// The function then iterates over the characters in the string S in the range [i, j). 
// For each character, it updates the balance bal by incrementing it 
// for each opening parenthesis and decrementing it for each closing parenthesis.

// If the balance becomes zero, it means that the current substring of S from 
// i to k is a balanced primitive string, and the function needs to compute its score.

// If the length of the primitive string is 2 (i.e., it consists of a pair of parentheses), 
// its score is 1.

// Otherwise, the function recursively computes the score of the primitive string by calling
// itself with the range [i+1, k] (i.e., excluding the outermost parentheses), and
// multiplies the result by 2 to account for the fact that there are two levels of parentheses.

// Finally, the function updates the value of i to k+1, so that the next primitive string 
// can be processed in the remaining range.

// The function returns the total score ans of the original balanced string.

// The time complexity of this algorithm is O(n^2), where n is the length of the input string S.
// This is because the function can potentially split the input string into n/2 primitive 
// substrings, and for each primitive substring, it may recursively process another n/2 
// primitive substrings. This results in a total of n^2 operations in the worst case.

// The space complexity is also O(n), because the function uses a recursive call stack that
// can potentially grow to a depth of n/2 in the worst case.






// APPROACH 2

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack;
        stack.push(0); 

        for(char c: S) {
            if(c == '(')
                stack.push(0);
            else{
                int v = stack.top();
                stack.pop();
                int w = stack.top();
                stack.pop();
                stack.push(w + max(2 * v, 1));
            }
        }
        return stack.top();
    }
};



// The given code uses a stack to keep track of the scores of each frame, 
// where a frame is a pair of opening and closing parentheses.
// Initially, a 0 is pushed onto the stack to represent the score of the outermost frame.

// Then, for each character in the given string, the following steps are taken:

// -> If the character is an opening parenthesis, a new frame with a score of 0 is pushed 
//    onto the stack.

// -> If the character is a closing parenthesis, the score of the current frame is calculated 
//    by retrieving the top two scores from the stack and using them to compute 
//    the score of the current frame according to the rules of the problem. 
//    The score of the current frame is then pushed onto the stack, 
//    representing the score of the enclosed sub-string.

// Finally, the score of the entire parentheses string is returned by retrieving the 
// top score from the stack.

// In summary, the code uses a stack to keep track of the scores of each frame 
// within the parentheses string, and computes the final score by 
// summing the scores of all the frames.

// T.C. --> O(N)
// S.C. --> O(N)








// APPROACH 3

class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, bal = 0;
        for(int i = 0; i < S.size(); ++i) {
            if(S.at(i) == '(') {
                bal++;
            }else{
                bal--;
                if(S.at(i-1) == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)
