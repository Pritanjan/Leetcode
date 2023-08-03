// APPROACH 1

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[s.size()];
    }    
};




// APPROACH 2

class Solution {
public:
    char findTheDifference(string s, string t) {        
        // count of ASCII of s & t
        int S = 0;
        int T = 0;
        
        // count all ASCII values of string s 
        for(char ch : s) S += ch;

        // count all ASCII values of string s 
        for(char ch : t) T += ch;
        
        //difference of count T-S is answer
        return T-S;
    }
};


// OR


class Solution {
public:
    char findTheDifference(string s, string t) {      
        int S = 0;
        for(char &ch : t) S += ch;
        for(char &ch : s) S -= ch;
        return (char)S;
    }
};






// APPROACH 3 [ Using Character Counts ]

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






// APPROACH 4 [ Using Xor]

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

