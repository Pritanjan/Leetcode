// https://leetcode.com/problems/maximum-of-absolute-value-expression/

class Solution {
public:
    int sum(vector<int> nums, int n){
        int max_sum = nums[0];
        int min_sum = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            max_sum = max(max_sum, nums[i]);
            min_sum = min(min_sum, nums[i]);
        }
        return (max_sum - min_sum);
    }
    
    int maxAbsValExpr(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        vector<int> sum1(n,0), diff1(n,0), sum2(n,0), diff2(n,0);
        
        for(int i=0; i<n; i++){
            sum1[i] = nums1[i] + nums2[i] + i;
            sum2[i] = nums1[i] + nums2[i] - i;
            diff1[i] = nums1[i] - nums2[i] + i;
            diff2[i] = nums1[i] - nums2[i] - i;
        }
        return max(max(sum(sum1, n), sum(sum2, n)), max(sum(diff1, n), sum(diff2, n)));
    }
};
