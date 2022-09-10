//https://leetcode.com/problems/reverse-prefix-of-word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int p = word.find(ch);    
        
        reverse(word.begin(), word.begin() + p+1);
        return word;
    }
};
