//https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        
        string str = s;
        reverse(s.begin(),s.end());
        
        if(s == str)
            return 1;
        else
            return 2;
    }
};

//C++ Solution
//possible cases
//case1 string is empty : return 0
//case2 string is palindrome return 1 cause 1 operation makes it empty
//case3 string is not a palindrome return 2 why ? since only 2 characters a and b are present in a string 1st operation removes all a's 2nd operation removes all b's
//example : string s= "abbabbabb" it is not a pallindrome ... so we look at subsequence of a's aaa : palindrome & subsequence of b's bbbbbb: a palindrome .
//Each string which is not a palindrome made up of a's and b's , will always have 2 palindromic subsequences
//

