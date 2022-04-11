// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        
        long long int i=0;
        // for(int i=0;i<INT_MAX;i++){
        
        while(i*i<=x)
            i++;
        
        return i-1;
    // }
        
    }
};
