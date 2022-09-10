// https://leetcode.com/problems/backspace-string-compare/
// Company Tag fb google
 
class Solution {
public:
    string answer(string s){
        string ans = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] != '#'){
                ans += s[i];
                i++;
            }
            while(s[i] == '#' && ans.size() > 0){
                ans.pop_back();
                i++;
            }
            while(s[i] == '#')
                i++;
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        string s1 = answer(s);
        string s2 = answer(t);
        
        if(s1 == s2)
            return true;
        else
            return false;
    }
};
