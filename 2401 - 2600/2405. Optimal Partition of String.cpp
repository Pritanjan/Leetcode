// APPROACH 1


// Here we iterate through the string s one character at a time, and keep track of the unique 
// characters seen so far using an unordered set (ust). The counter variable res keeps
// track of the number of substrings seen so far.

// For each character c in the string, we check if it is already in the unordered set.
// If it is, then we know that we have seen this character before and need to start a new
// substring. Therefore, we clear the unordered set and increment the counter res.

// After that, we insert the current character c into the unordered set to continue 
// building the current substring.

// Finally, we return res + 1 because the number of substrings seen so far is one less 
// than the total number of substrings.
  

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> ust;  // curChars
        int res = 0;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if (ust.count(c) > 0) {
                ust.clear();
                res++;
            }
            ust.insert(c);
        }
        return res + 1;
    }
};






