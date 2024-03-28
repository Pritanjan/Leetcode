// A 1

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        
        int res = 0;
        while(j < n) {
            if(mp[nums[j]] > k) {
                while(i < j && mp[nums[j]] > k) {
                    if(mp[nums[i]] != 1) mp[nums[i]]--; 
                    else mp.erase(nums[i]);
                    
                    i++;
                }
            }
            res = max(res, j-i+1);
            j++;
        }        
        return res;
    }
};

