class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=nums.size()-1; i>=0; i--){
            bool flag = false;
            for(auto& p : res) {
                if(find(p.begin(), p.end(), nums[i]) == p.end()) {
                    p.push_back(nums[i]);
                    flag = true;
                    break;
                }
            }
            
            if(!flag) res.push_back({nums[i]});
            
        }
        return res;
    }
};
