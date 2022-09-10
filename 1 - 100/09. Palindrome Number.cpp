//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
       long long int p=0,q;
        long int n = x;
        if(x<0){
            return false;
        }
        while(x!=0){
            q=x%10;
            p=p*10+q;
            x=x/10;
        }
                
        if(p==n)
            return true;
       else
            return false;
    }
};
