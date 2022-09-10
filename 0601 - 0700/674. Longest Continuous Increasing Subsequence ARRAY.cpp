// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        
        int ans   = 1;
        int count = 1;
            
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                count++;
                ans = max(ans,count);
            }
            else 
                count = 1;
        }
        return ans;
    }
};
