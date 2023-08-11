// APPROACH 1

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

