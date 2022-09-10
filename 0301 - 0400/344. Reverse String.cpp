// https://leetcode.com/problems/reverse-string/submissions/

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin() , s.end() ); 
        return s;
    }
};

