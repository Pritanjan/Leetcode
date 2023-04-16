class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        long long max_val = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_val = max(max_val, (long long)nums[i]);
            ans[i] = nums[i] + max_val;
        }
        
        for(int i=1; i<n; i++) ans[i] += ans[i-1];
        
        return ans;
    }
};



