// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        
        for(int i=0;num!=0; i++)
        {
            while(num>= ans[i])    
            {
                num = num - ans[i];
                ret = ret + str[i];
            }
        }
        return ret;
    }
};
