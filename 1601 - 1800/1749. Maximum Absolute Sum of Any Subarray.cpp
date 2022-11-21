class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int ans = 0, max_sum = 0, min_sum = 0;
	   
        for(int i=0; i<nums.size(); i++){
            min_sum = min(0, nums[i] + min_sum);
            max_sum = max(0, nums[i] + max_sum);
            
            ans = max({ans, max_sum, -min_sum});
	   }
	   return ans;
    }
};






