// A1 

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(curr);
            return ;
        }
        
        for(int i=start; i<candidates.size(); ++i) {
            if(i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            if(candidates[i] > target) continue; // Skip if current candidate is too large
            
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, curr, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, res);
        return res;
    }
};







// A2





