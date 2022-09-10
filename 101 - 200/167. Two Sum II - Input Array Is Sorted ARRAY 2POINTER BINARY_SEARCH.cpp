// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        // int mid;
        // vector<int> ans;
        
        while(L < R){
            // mid = (L + R)/2;
            // for(int i=0; i<nums.size();)
            if(nums[L] + nums[R] == target){
                // ans.push_back(L);
                
				// ans.push_back(R);
                return {L+1, R+1};
            }
            else if(nums[L] + nums[R] > target)
                R--;
            else
                L++;
                
        }
        return {};
    }
};
