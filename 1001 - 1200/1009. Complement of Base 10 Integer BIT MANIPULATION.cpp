// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
            return 1;
        int m = n;
        int q = 0;
        
        while(m!=0){
            q = (q<<1) | 1;
            m = m>>1;
        }
        int ans = (~n) & q;
        
        return ans;
    }
};
