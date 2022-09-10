//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MIN;
        
        int target = -x;
        for(auto i : nums)
            target += i;
        
        if(target < 0)
            return -1;
        
        int j = 0;
        // int sum = accumulate(nums.begin(),nums.end(),0); 
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum > target){
                sum -= nums[j];
                j++;
            }
        
            if(sum == target)
                ans = max(ans, i-j+1);
        }
         
        return ans==INT_MIN ? -1 : nums.size() - ans;
    }
};
