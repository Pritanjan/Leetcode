class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long start = 0, end = 0;
        
        while(end < n) {
            if(nums[end] == 0) {
                end++;
            }else{
                count += (end - start) * (end - start + 1) / 2;
                start = end + 1;
                end = start;
            }
        }
        
        if (nums[n-1] == 0) {
            count += (end - start) * (end - start + 1) / 2;
        }
        
        return count;
    }
};

