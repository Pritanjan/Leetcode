// APPROACH 6 Brute Force

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(char c : t) {
            size_t pos = t.find(c);
            string temp = t.substr(0, pos) + t.substr(pos+1);
            if(temp == s) return c;
        }
        return '\0'
    }
};




// APPROACH 1  Using Sorting and Comparing

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[s.size()];
        // return t.back();
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





// APPROACH 3 [ Using Character Counts ]  Hashing

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





// APPROACH 4 [ Using Xor ] Bit Manipulation:

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






// APPROACH 5 [ Using Set ]

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_set<char> charSet(s.begin(), s.end());
        for(char c : t) {
            if(charSet.find(c) == charSet.end()) return c;
        }
        return '\0';        
    }
};











