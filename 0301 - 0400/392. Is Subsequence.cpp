// APPROACH 1 [ 2 Pointer ] 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < t.length()){
            if(s.at(i) == t.at(j)){
                i++;
            }
            j++;
        }
        return i == s.length());  // If i reaches the end of s, then s is a subsequence of 
    }
};





// APPROACH 2 USE FIND FUNCTION 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t pos = 0; // Position to search for character in t
        for(char c : s) {
            pos = t.find(c, pos); // Search for the character in t starting from pos
            if(pos == string::npos) {
                return false; // Character not found in t
            }
            pos++; // Move to the next position in t
        }
        
        return true;
    }
};






// APPROACH 3 GREEDY 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        for(char c : t) {
            if(i < s.length() && s[i] == c) {
                i++; // Move pointer in s if characters match
            }
        }
        return i == s.length();
    }
};








// APPROACH 4 DP

