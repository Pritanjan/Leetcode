//https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() <= 1)
            return {nums};
        
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size(); i++){
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto a = permute(v);
            
            for(int j=0; j<a.size(); j++){
                vector<int> v1 = a[j];
                v1.insert(v1.begin(), nums[i]);
                ans.push_back(v1);
            }
        }
        return ans;
    }
};

// Recursive
class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx >= n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            swap(nums[idx], nums[i]);
            permute(idx+1, nums);
            swap(nums[idx], nums[i]); // reset //the num vector is passed by reference, so if it is not not reset, the next iteration will have the wrong vector to begin
//this is the "backtracking" portion
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(0, nums);
        return ans;
    }
};

//3rd

class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx = n){
            ans.push_back(nums);
        }
        else{
            for(int i=idx; i<n; i++){
                swap(nums[idx], nums[i]);
                permute(idx+1, nums);
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }
};

