// APPROACH 1 [ BRUTE FORCE ] 

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





// APPROACH 2 [  String Concatenation ]

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if(t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};

// Yes, we check if T is a rotated version of S by checking if it is a substring of S + S. 
// This is because S + S contains all of the rotations of S.



