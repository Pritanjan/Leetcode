// A 1  Using Sorting and Comparing

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[s.size()];
        // return t.back();     // Return the last character if no extra character is found
    }    
};






// A 2

class Solution {
public:
    char findTheDifference(string s, string t) {        
        int S = 0;                   // count of ASCII of s
        int T = 0;                   // count of ASCII of t
        for(char ch : s) S += ch;    // count all ASCII values of string s 
        for(char ch : t) T += ch;    // count all ASCII values of string s 
        return T - S;                // difference of count T-S is answer
    }
};


// OR


// Mathematical Sum
class Solution {
public:
    char findTheDifference(string s, string t) {      
        int Sum = 0;
        for(char &ch : t) Sum += ch;
        for(char &ch : s) Sum -= ch;
        return (char)Sum;
        // return static_cast<char>(sum);
    }
};






// A 3 [ Using Character Counts ]  Hashing
// Count the frequency of characters in both strings.
// Compare the character counts to find the added letter.

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        for(char c : t) {
            if(--freq[c] < 0) return c;
        }
        return '\0';
    }
};


// OR
// Using Counting Arrays 

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);  // char cnt
        for(char c : s) v[c - 'a']++;
        for(char c : t) {
            if(--v[c - 'a'] < 0) {
                return c;
            }
        }
        return '\0';
    }
};






// A 4 [ Using Xor ] Bit Manipulation
// XOR all the characters in both strings.
// The result will be the ASCII value of the added letter.
// It works because XORing a character with itself cancels out, leaving only the added letter.
    
class Solution {
public:
    char findTheDifference(string s, string t) {      
        char res = 0;
        for(char &ch : t) res ^= ch;
        for(char &ch : s) res ^= ch; 
        return res;
    }
};






// A 5 










