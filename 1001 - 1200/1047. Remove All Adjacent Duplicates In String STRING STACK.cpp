// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

//  use string as a stack.

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0 ;
        for(int j=1; j<s.length(); j++){
            i < 0 || s[i] != s[j] ?  s[++i] = s[j] : --i;
        }
        return s.substr(0,i+1);
    }
};

