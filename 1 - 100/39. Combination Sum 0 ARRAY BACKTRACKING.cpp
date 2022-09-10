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
