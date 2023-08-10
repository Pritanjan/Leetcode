// APPROACH 1 [ BRUTE FORCE ]

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                int sum = 0;
                for(int k=i; k<=j; ++k) {
                    sum += nums[k];
                }
                mx = max(mx, sum);
            }
        }        
        return mx;
    }
};

// T.C. - O(N^3)





// APPROACH 2 [ OPTIMISING APPROACH 1 ]

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0; i<n; ++i) {
            int sum = 0;
            for(int j=i; j<n; ++j) {
                sum += nums[j];
                mx = max(mx, sum);
            }
        }        
        return mx;
    }
};

 

// APPROACH 3 [ Kadane's Algorithm ]

// Iterate through the array, keeping track of the current sum (Sum).
// Update the maximum sum (maxSum) if currentSum is greater.
// If Sum becomes negative, reset it to zero.
// Time : O(n)
	
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum = 0, ma = nums[0] ;
	    
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








// APPROACH 4 [ DP ]

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






// APPROACH 5 [ Divide and Conquer ]

class Solution {
public:
    int f(vector<int>& nums, int L, int R) {
        if(L == R) return nums[L];
                
        int mid = L + (R-L) / 2;
        int Lmx = f(nums, L, mid);
        int Rmx = f(nums, mid+1, R);
        
        int leftBorderMax = INT_MIN;
        int sum = 0;
        for(int i=mid; i>=L; --i) {
            sum += nums[i];
            leftBorderMax = max(leftBorderMax, sum);
        }
        
        int rightBorderMax = INT_MIN;
        sum = 0;
        for(int i=mid+1; i<=R; ++i) {
            sum += nums[i];
            rightBorderMax = max(rightBorderMax, sum);
        }        
        return max(max(Lmx, Rmx), leftBorderMax + rightBorderMax);
    }     
    
    int maxSubArray(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);    
    }
};





// APPROACH 6


