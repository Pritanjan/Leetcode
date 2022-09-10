//https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void findcombination(int i, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
        
        if(target == 0){
            ans.push_back(ds);
            return;
        }
           
        
        for(int j=i; j<nums.size(); j++){
            if(i < j && nums[j] == nums[j-1])  // nums[j] == nums[j-1] -> avid picking up duplicate element
                continue;
            if(nums[j] > target)
                break;
            else{
                ds.push_back(nums[j]);
                findcombination(j+1, target-nums[j], nums, ans, ds);
            
            }
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0, target, candidates, ans, ds);
        return ans;
    }
}; 


