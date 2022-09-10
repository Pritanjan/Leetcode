//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void findcombination(int i, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
        if(i == nums.size()){
            if(target == 0)
                ans.push_back(ds);
            return ;
        }
        if(nums[i] <= target){
            ds.push_back(nums[i]);
            findcombination(i, target-nums[i], nums, ans, ds);
            ds.pop_back();
        }
        
        findcombination(i+1, target, nums, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0, target, candidates, ans, ds);
        return ans;
    }
}; 

