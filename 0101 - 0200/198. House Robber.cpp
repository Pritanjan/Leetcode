// A 1

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        int temp = 0;        
        for(int i=0; i<nums.size(); i++) {
            temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1 ;
            prev1 = temp;
        }
        return temp;
    }
};

// Time Complexity  : O(N)
// Space Complexity : O(1)


// OR

// 1. Use 3 variables to store the amount of money the robber have if robbed in previous three houses;
//    for the current house the amount will be the either :
// 2. if robbed amount in 2 last house is more than 3rd last then robbed money for current house will be
//    the sum of money in current house and 2 last house.
// 3. else the robbed amount in current house would be the sum of money in current and 3rd last house.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0]
            
        int notRobbed = 0;          // Maximum profit when the current house is not robbed
        int justRobbed = nums[0];   // Maximum profit when the current house is just robbed
        int robbed = 0;             // Maximum profit when the current house is robbed
        for(int i=1; i<n; ++i) {
            int tmp = notRobbed;          // Store the previous notRobbed value
            notRobbed = max(notRobbed, max(justRobbed, robbed)); // Transition to the next notRobbed state
            justRobbed = tmp + nums[i];   // Transition to the next justRobbed state
            robbed = justRobbed;          // Transition to the next robbed state
        }
        return max(notRobbed, max(justRobbed, robbed)); // Return the maximum profit among all states
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 2  -  DP
  
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        // Create an array to store the maximum amount of money robbed up to the current house
        vector<int> dp(n, 0);
        // Initialize the first two elements of dp
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill in the dp array
        for(int i=2; i<n; ++i) {
            // Decide whether to rob the current house or not
            // If we rob the current house (i), we add its value to the maximum from two houses ago (i - 2)
            // If we skip the current house, we take the maximum from the previous house (i - 1)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        // The last element of dp contains the maximum amount that can be robbed
        return dp[n-1];
    }
};
// T.C. --> O(N)

// OR

class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        
        vector<int> dp(n, -1);
        return f(n-1, arr, dp);
    }

private:
    int f(int i, vector<int>& arr, vector<int>& dp) {
        if(i == 0) return arr[i];
        if(i < 0)  return 0;
        if(dp[i] != -1) return dp[i];
        
        int notake = f(i-1, arr, dp);
        int take = arr[i] + f(i-2, arr, dp);
        
        return dp[i] = max(take, notake);
    }
};






// A 3 - Recursive Approach with Memoization (Top-Down DP)

class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> mp;
        return recursion(nums, nums.size() - 1, mp);
    }
private:
    int recursion(const vector<int>& nums, int i, unordered_map<int, int>& mp) {
        if(i < 0) return 0;
        if(mp.count(i)) return mp[i];
        int curr = nums[i] + recursion(nums, i-2, mp);
        int skip = recursion(nums, i-1, mp);
        int res = max(curr, skip);
        mp[i] = res;
        return res;
    }
};

// T.C. --> O(N)






// A 4 - Greedy Approach
// Use a greedy strategy by considering whether to rob each house based on the amount of money
// it contains.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int evSum = 0;
        int odSum = 0;
        for(int i=0; i<n; ++i) {
            if(i % 2 == 0) {
                evSum += nums[i];
                evSum = max(evSum, odSum);
            } 
            else {
                odSum += nums[i];
                odSum = max(evSum, odSum);
            }
        }
        return max(evSum, odSum);
    }
};






// A 5 -  Using Two Arrays
// Modification of the DP approach but uses two arrays instead of just two variables. 
// One array stores the maximum robbed amount considering the current house, and
// other array stores maximum robbed amount without considering current house.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> rob(n, 0);
        vector<int> skip(n, 0);
        rob[0] = nums[0];
        for(int i=1; i<n; ++i) {
            rob[i] = skip[i - 1] + nums[i];
            skip[i] = max(rob[i - 1], skip[i-1]);
        }
        return max(rob[n-1], skip[n-1]);
    }
};






// A 6
