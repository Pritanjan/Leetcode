// https://leetcode.com/problems/valid-anagram/
// COMPANY TAG BLOOMBERG MICROSOFT FB

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        for(int i=0; i<s2.size(); i++){
            if(s1[i] !=s2[i])
                return false;
        }
        return true;
    }
};


