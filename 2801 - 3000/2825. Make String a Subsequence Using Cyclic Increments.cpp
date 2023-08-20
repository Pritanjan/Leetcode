// APPROACH 1 

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size() > str1.size()) return false;
        int p = 0;
        for(int i=0; i<str1.size(); i++) {
            if(p < str2.size() && str1[i] == str2[p]) p++;
            else if(p < str2.size() && ((str1[i]-'a'+1)%26 + 'a') == str2[p]) p++;
        }        
        return p == str2.size();
    }
};


