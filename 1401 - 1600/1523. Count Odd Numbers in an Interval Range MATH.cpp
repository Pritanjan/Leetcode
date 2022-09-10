// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
public:
    int countOdds(int L, int R) {
        int ans = (R-L)/2;
        if(L%2!=0 || R%2!=0)
            ans++;
        
        return ans;
        
    }
};
