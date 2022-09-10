//https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

class Solution {
public:
    string greatestLetter(string s) {
        
        // for(char c='a'; c<='z'; c++)  --> it is not using to get greatest English letter
        
        for(char c='z'; c>='a'; c--){
            if( find(s.begin(), s.end(),c) != s.end()  && find(s.begin(), s.end(), toupper(c)) != s.end() )
                return string(1, toupper(c));
        }
        return "";
    }
};
