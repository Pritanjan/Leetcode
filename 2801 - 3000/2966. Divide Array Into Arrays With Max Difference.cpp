// A 1

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i += 3) {
            if(i+2 < nums.size() && nums[i+2] - nums[i] <= k) {
                vector<int> v{nums[i], nums[i+1], nums[i+2]};
                res.push_back(v);
            }
            else return {};
        }
        return res;
    }
};
