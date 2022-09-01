//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        int p=0;
        
        if(x<0)
            return false;
        else{
            while(x!=0){
            x=x%10;
            p=p*10 + x;
            x=x/10;
            }
        }
        
        if(p==x)
            return true;
        return false;
    }
};
