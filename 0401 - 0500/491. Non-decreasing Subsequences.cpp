// APPROACH 1 backtrack

class Solution {
public:
    void f(int idx, vector<vector<int>> &res, vector<int> v, vector<int> nums){
        if(idx >= nums.size()){
            if(v.size() >= 2) res.push_back(v);
            return ;
        }

        if(v.empty() or nums[idx] >= v.back()){
            v.push_back(nums[idx]);
            f(idx+1, res, v, nums);
            v.pop_back();
        }

        if(idx > 0 and !v.empty() and nums[idx] == v.back()) return ;
        f(idx + 1, res, v, nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        f(0, res, v, nums);
        return res;
    }
};


// OR


class Solution {
public:
    void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size() >= 2) res.push_back(curr);
        
        for(int i=idx; i<nums.size(); ++i) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(curr.empty() || nums[i] >= curr.back()) {
                curr.push_back(nums[i]);
                backtrack(nums, i+1, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }
};


// OR


class Solution {
public:    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> set_res;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            if (path.size() >= 2) set_res.insert(path);
            for (int j = i; j < nums.size(); j++) {
                if (path.empty() || nums[j] >= path.back()) {
                    path.push_back(nums[j]);
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
    
        dfs(0);
        for(auto v: set_res) res.push_back(v);
        return res;
    }
};






// APPROACH 2 Bitmasking

class VectorCompare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a.size() < b.size() || (a.size() == b.size() && a < b);
    }
};

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        set<vector<int>, VectorCompare> uniqueSubsequences;

        for(int mask=0; mask<(1 << n); ++mask) {
            vector<int> subsequence;
            for(int i=0; i<n; ++i) {
                if(mask & (1 << i)) {
                    if(subsequence.empty() || nums[i] >= subsequence.back()) subsequence.push_back(nums[i]);
                }
            }
            if(subsequence.size() >= 2) uniqueSubsequences.insert(subsequence);
        }

        for(const auto& i : uniqueSubsequences) res.push_back(i);
        return res;
    }
};


