// len gives the number of elements >= nums[i]  i.e. the number pf elements on its right

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int len = n - i;
            
            if((i==0 || len > nums[i-1]) && len <= nums[i]){
                return i=len;
            }
        }
        return -1;
    }
};
