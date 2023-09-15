// A1  Backtracking

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





// A 2  -  Recursion

class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, int idx, vector<int>& curr,vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(curr);
            return ;
        }        
        if(idx >= candidates.size() || target < 0) return ;
        
        // Include the current candidate
        curr.push_back(candidates[idx]);
        findCombinations(candidates, target - candidates[idx], idx+1, curr, res);
        curr.pop_back();
        
        // Skip duplicates
        while(idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) idx++;
        
        // Exclude the current candidate
        findCombinations(candidates, target, idx+1, curr, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        findCombinations(candidates, target, 0, curr, res);
        return res;
    }
};






// A3

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        int strt = 0;
        
        function<void(int, int)> backtrack = [&](int rem, int idx) {
            if(rem == 0) {
                res.push_back(curr);
                return ;
            }
            
            for(int i=idx; i<candidates.size() && candidates[i] <= rem; i++) {
                if(i > idx && candidates[i] == candidates[i-1]) continue; // Skip duplicates
                curr.push_back(candidates[i]);
                backtrack(rem - candidates[i], i + 1);
                curr.pop_back();
            }
        };
        
        backtrack(target, strt);
        return res;
    }
};






// A 4

