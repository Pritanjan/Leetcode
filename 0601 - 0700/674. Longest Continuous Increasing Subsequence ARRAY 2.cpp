https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int ans   = 1;
        int count = 1;
            
        for(int i=0; i<nums.size()-1; i++){
            ans = max (ans, nums[i] < nums[i+1] ? ++count : count = 1);
            }
            return ans;
    }
};


