class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> count(128);
        vector<bool> used(128);

        // Count the frequency of each character in the string
        for(const char c : s) ++count[c];

        // Iterate over the string and remove duplicate characters
        for(const char c : s) {
            --count[c];
            
            if (used[c]) continue;

            while (!ans.empty() && ans.back() > c && count[ans.back()] > 0) {
                used[ans.back()] = false;
                ans.pop_back();
            }
            
            used[c] = true;
            ans.push_back(c);
        }

        return ans;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)

// The given code is a C++ program that implements a function called "removeDuplicateLetters" which takes a string as input and returns a string with duplicate letters removed. The code uses two vectors, "count" and "used", to keep track of the frequency of characters in the string and whether a character has already been used, respectively. The function then iterates over the string and removes duplicate characters while maintaining the original order of the characters in the string.
    
// The function initializes an empty string called "ans" and two vectors "count" and "used", each of size 128. It then counts the frequency of each character in the input string using a for-each loop, and updates the "count" vector accordingly.

// The function then iterates over each character in the input string and does the following for each character:

// -> Decrement the frequency of the current character in the "count" vector.
// -> If the current character has already been used, continue to the next character.
// -> While the "ans" string is not empty and the last character in the "ans" string is greater than the current character, and the frequency of the last character in the "count" vector is greater than 0, remove the last character from the "ans" string and mark it as unused in the "used" vector.
// -> Mark the current character as used in the "used" vector and append it to the "ans" string.
// Finally, the function returns the resulting string with duplicate characters removed.

    
