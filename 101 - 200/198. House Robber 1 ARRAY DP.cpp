//https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev1 = 0, prev2 = 0;
        int temp = 0;
        
        for(int i=0; i<nums.size(); i++) {
            temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1 ;
            prev1 = temp;
        }
        return temp;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
