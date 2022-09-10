// https://leetcode.com/problems/arranging-coins/

// Binary Search

class Solution {
public:
    int arrangeCoins(int n) {
        long L = 0;
        long R = n;
        
        long mid, a;
        
        while(L <= R){
            mid = (L + R)/2;
            a = mid * (mid + 1)/2;
            
            if(a == n)
                return mid;
            
            else if(a > n)
                R = mid - 1;
            else
                L = mid + 1;
            
        }
        return R;
    }
};
