//https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        
        for(auto i : nums){
            if(i <= c1)
                c1 = i ;
            else if(i <= c2)
                c2 = i;
            else 
                return true;
        }
        return false;
    }
};
