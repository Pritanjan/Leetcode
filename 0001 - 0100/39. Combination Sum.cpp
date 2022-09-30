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
        vector<vector<int>> ans;   // it will store stroes all the combiination which we are going to return ultimately
        vector<int> ds;         // this ds is used in oiur recursion
        findcombination(0, target, candidates, ans, ds);
        return ans;
    }
}; 






class Solution {
public:
    vector<vector<int>> ans;
    
    void findcombination(int i, vector<int>& candidates, int target, vector<int> ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        if(target <= 0)
            return;
        
        if(i == candidates.size())
            return;
        
        findcombination(i+1, candidates, target, ds);
        
        ds.push_back(candidates[i]);
        findcombination(i, candidates, target-candidates[i], ds);
        
        ds.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        findcombination(0, candidates, target, ds);
        return ans;
    }
};







