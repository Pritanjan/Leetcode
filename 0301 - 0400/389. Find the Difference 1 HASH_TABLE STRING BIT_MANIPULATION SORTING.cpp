//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        // count of ASCII of s & t
        int S = 0;
        int T = 0;
        
        // count all ASCII values of string s 
        for(char ch : s)
            S += ch;
        
        // count all ASCII values of string s 
        for(char ch : t)
            T += ch;
        
        //difference of count T-S is answer
        return T-S;
    }
};


