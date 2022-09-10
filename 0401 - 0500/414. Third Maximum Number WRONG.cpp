// https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        
        
        sort(nums.begin(), nums.end() );
        
        
        if(nums.size()>=3) {
            nums.pop_back();
            nums.pop_back();
            reverse(nums.begin(), nums.end());
            return nums[0];
        }
        else{
            reverse(nums.begin(), nums.end());
            return nums[0];
        }
            
    }
};
