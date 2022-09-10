//https://leetcode.com/problems/longest-common-prefix/
//Horizontal Scanning

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string s1 = s[0];
        if(s.empty())
            return "";
        
        for(int i=0; i<s.size(); i++){
            while(s[i].find(s1) != 0){
                s1 = s1.substr(0, s1.size() -1);
            }
            if(s1.empty())
                return "";
        }
        return s1;
    }
};
