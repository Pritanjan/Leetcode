//https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        vector<int> ans(n);
        int j = 0;
        
        for(auto i : nums){
            if(i < pivot)
                ans[j++] = i;
        }
        
        for(auto i : nums){
            if(i == pivot)
                ans[j++] = i;
        }
        
        for(auto i : nums){
            if(i > pivot)
                ans[j++] = i;
        }
        
        return ans;
    }
};
