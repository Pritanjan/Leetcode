// https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        // if size is less than or equal to 1 then it is palidrome
        if(n <= 1)
            return "";
        for(int i=0; i<n/2; i++){
            // replace first non  'a' charracter to get lexigraphically smallest word
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        //if the string is all a's => "aaaaa", then replace the last character with 'b'
        palindrome.pop_back();
        palindrome += 'b';
        return palindrome;
    }
};
