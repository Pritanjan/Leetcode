//https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int a = 0;
        for(int i = 0; i <= s.length(); ++i){
            if(s[i] == ' '){
                reverse(&s[a], &s[i]);
                a = i + 1;
            }
        }
        reverse(s.begin()+a, s.end());
        return s;
    }
};





