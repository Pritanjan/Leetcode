// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        
        int m = 1;
        while(m<= n){
            n = n^m;
            m = m<<1;
        }
        return n;
    }
};
