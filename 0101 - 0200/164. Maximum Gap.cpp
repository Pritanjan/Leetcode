// https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // if(nums.size() < 2)
            // return 0;
        
        int dif=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            dif = max(dif, nums[i+1] - nums[i]);
        }
        
        return dif;
    }
};
