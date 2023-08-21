// APPROACH 1 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();    
        for(int j=1; j<=n/2; ++j) {
            if(n % j == 0) {
                string substring = s.substr(0, j);
                string res = "";
                for(int i=0; i<n/j; ++i) {
                    res += substring;
                }
                if(res == s) return true;
            }
        }        
        return false;
    }
};


