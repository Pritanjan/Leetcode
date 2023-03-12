class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();    
        sort(nums.begin(), nums.end(), greater<int>());
    
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(prefix[i] > 0) {
                res = max(res, i+1);
            }
        }
        return res;
    }
};




