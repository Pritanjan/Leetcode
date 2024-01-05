// A 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<int> v(n,1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && v[i] < v[j] + 1){
                    v[i] = v[j] + 1;
                }
            }
        }
        return *max_element(v.begin(), v.end());
    }
};






// A 2 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> dp(n, 1);
        int maxLength = 1;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
