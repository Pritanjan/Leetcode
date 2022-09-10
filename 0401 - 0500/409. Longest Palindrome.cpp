//https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        // for(char i : s){
        for(char i='A'; i<='z'; i++){
            odd += count(s.begin(), s.end(), i) & 1;
        }    
        return s.size() - odd + (odd > 0);
    }
};


