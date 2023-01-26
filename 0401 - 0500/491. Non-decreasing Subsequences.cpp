class Solution {
public:
    void f(int idx, vector<vector<int>> &res, vector<int> v, vector<int> nums){
        if(idx >= nums.size()){
            if(v.size() >= 2)
                res.push_back(v);
            return ;
        }

        if(v.empty() or nums[idx] >= v.back()){
            v.push_back(nums[idx]);
            f(idx + 1, res, v, nums);
            v.pop_back();
        }

        if(idx > 0 and !v.empty() and nums[idx] == v.back())
            return ;

        f(idx + 1, res, v, nums);
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        f(0, res, v, nums);

        return res;
    }
};
