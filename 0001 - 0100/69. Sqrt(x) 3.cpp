// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    
    int binarysearch(int n){
        int l = 0;
        int r = n;
        int mid ;
        long long  int ans = -1;
        
        while(l<=r){
            long long int mid = l + (r-l)/2;
            long long int sq = mid * mid ;
            
            if(sq == n)
                return mid;
            if(sq < n){
                ans = mid;
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return binarysearch(x) ;
    }
};
