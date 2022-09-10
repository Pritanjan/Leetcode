// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

class Solution {
public:
    string removeDigit(string s, char digit) {
        string ans;
        
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == digit)
                ans = max(s.substr(0,i) + s.substr(i+1), ans);
        }
        return ans;
    }
};
