//https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx >= n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> ust;
        for(int i=idx; i<n; i++){
            if(ust.count(nums[i]))
                continue;
            if(idx != i  && nums[idx] == nums[i])
                continue;
            ust.insert(nums[i]);
            
            swap(nums[idx], nums[i]);
            permute(idx+1, nums);
            swap(nums[idx], nums[i]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(0, nums);
        return ans;
    }
};
