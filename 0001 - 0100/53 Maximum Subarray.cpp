// APPROACH 1 [ Kadane's Algorithm ]

// Iterate through the array, keeping track of the current sum (Sum).
// Update the maximum sum (maxSum) if currentSum is greater.
// If Sum becomes negative, reset it to zero.
// Time : O(n)
	
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
	    if(sum < 0) sum = 0;
	}
	return ma;
    }
};







// APPROACH 2 [ DP ]

// Create an array dp of the same size as the input array.
// dp[i] shows maximum sum of a subarray ending at index i.
// Iterate through the array, updating dp[i] as the maximum of dp[i-1] + nums[i] and nums[i].
// Return the maximum value in the dp array as the largest sum.
// Time complexity: O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int mx = dp[0];

        for(int i=1; i<n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};

