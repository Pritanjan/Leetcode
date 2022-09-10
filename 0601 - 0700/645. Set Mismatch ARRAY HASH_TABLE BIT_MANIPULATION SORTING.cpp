// https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1);
        for(int i=0; i<nums.size(); i++){
            while(nums[i] != i+1){
                if(nums[i] == nums[nums[i] - 1]){
                    // ans.push_back(nums[i]);
                    // ans.push_back(i + 1);
                    ans[0] = nums[i];
                    ans[1] = i + 1;
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return ans;
    }
};
