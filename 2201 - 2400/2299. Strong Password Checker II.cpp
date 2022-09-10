//https://leetcode.com/problems/strong-password-checker-ii/

class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        int n = s.size();
        
        if(n < 8)
            return false;
        bool low = false;
        bool up  = false;
        bool dgt = false;
        bool spe = false;
        
        for(int i=0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                up = true;
            else if(s[i] >= 'a' && s[i] <= 'z')
                low = true;
            else if(isdigit(s[i]))
                dgt = true;
            else
                spe = true;
        }
        
        
        for(int i=0; i+1<n; i++){
            if(s[i] == s[i+1])
                return false;
        }
        
        if(low && up && dgt && spe )
            return true;
        else
            return false;
        
    }
};
