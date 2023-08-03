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





// APPROACH 3

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


