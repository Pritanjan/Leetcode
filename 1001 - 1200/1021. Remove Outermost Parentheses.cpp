// APPROACH 1

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






// APPROACH 1 WITH DETAIL EXPLANATION LINE BY LINE

// 1. Initialize a variable count to store the number of opening parentheses, i.e. ‘(‘.
// 2. Add every ‘(‘ to the result if count is greater than 0, i.e. add all ‘(‘ after 
//    the first ‘(‘ of a primitive substring is encountered.
// 3. Add every ‘)’ to the result if count is greater than 0, i.e. add all ‘)’ before 
//    the last ‘)’ of a primitive substring is encountered.
// 4. Finally, print the resultant string obtained.


#include <bits/stdc++.h>
using namespace std;

// Function to remove the outermost
// parentheses of every primitive
// substring from the given string
string removeOuterParentheses(string S)
{

    // Stores the resultant string
    string res;

    // Stores the count of
    // opened parentheses
    int count = 0;

    // Traverse the string
    for (char c : S) {

        // If opening parentheses is
        // encountered and their
        // count exceeds 0
        if (c == '(' && count++ > 0)

            // Include the character
            res += c;

        // If closing parentheses is
        // encountered and their
        // count is less than count
        // of opening parentheses
        if (c == ')' && count-- > 1)

            // Include the character
            res += c;
    }
    // Return the resultant string
    return res;
}

// Driver Code
int main()
{
    string S = "(()())(())()";
    cout << removeOuterParentheses(S);
}

// Output: 
// ()()()
 

// Time Complexity: O(N) where n is number of elements in given string. 
// As, we are using a loop to traverse N times so it will cost us O(N) time 

// Auxiliary Space: O(N), as we are using extra space for stack.





