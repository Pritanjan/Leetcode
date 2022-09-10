// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n; i++){
            int p = abs(nums[i]) - 1;
            nums[p] = (nums[p] > 0 ? -nums[p] : nums[p] );
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] >0 )
                ans.push_back(i+1);
        }
        
        return ans;
    }
};
