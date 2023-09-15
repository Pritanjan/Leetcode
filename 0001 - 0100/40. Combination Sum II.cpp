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

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        deque<int> comb;
        
        unordered_map<int, int> mp;
        for(int candidate : candidates) {
            if(mp.find(candidate) != mp.end()) mp[candidate]++;
            else mp[candidate] = 1;
        }
        
        // Convert the counter table to a list of (num, count) tuples
        vector<pair<int, int>> v;
        for(auto it : mp) {
            v.push_back(make_pair(it.first, it.second));
        }
        backtrack(comb, target, 0, v, res);
        return res;
    }
private:
    void backtrack(deque<int>& comb, int rem, int curr, vector<pair<int, int>>& v, vector<vector<int>>& res) {
        if(rem <= 0) {
            // Make a deep copy of the current combination
            if(rem == 0) res.push_back(vector<int>(comb.begin(), comb.end()));
            return ;
        }
        
        for(int i=curr; i<v.size(); ++i) {
            int candidate = v[i].first;
            int freq = v[i].second;
            
            if(freq <= 0) continue ;
            
            // Add a new element to the current combination
            comb.push_back(candidate);
            v[i].second--;
            
            // Continue the exploration with the updated combination
            backtrack(comb, rem - candidate, i, v, res);
            
            // Backtrack the changes, so that we can try another candidate
            v[i].second++;
            comb.pop_back();
        }
    }
};


