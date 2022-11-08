//https://leetcode.com/problems/maximum-subarray/

// Amazon D. E. Shaw Facebook Goldman Sachs Google LinkedIn Microsoft
// Ola PayPal PayU Samsung Snapdeal Teradata Visa Yahoo Zoho

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0, ma = nums[0] ;
       for(int i=0; i<nums.size(); i++){
            // step 1 add new elements
	    sum += nums[i];
           
            // step 1 add new elements
	    ma = max(ma, sum);
			
            // step 3 check sum 
	    if(sum < 0)
		 sum = 0;
	}
	return ma;
    }
};
