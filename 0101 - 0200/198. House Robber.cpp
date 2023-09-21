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


class Solution {
public:
    int rob(vector<int>& nums) {
        int h1 = 0, h2 = 0, h3 = 0;
        int temp = 0;        
        for(int i=0; i<nums.size(); i++) {
            temp = nums[i] + max(h2,h3) ;
            h3 = h2;
            h2 = h1;
            h1 = temp;
        }
        return max(h1,h2);
    }
};
 
// 1. Use 3 variables to store the amount of money the robber have if robbed in previous three houses;
//    for the current house the amount will be the either :
// 2. if robbed amount in 2 last house is more than 3rd last then robbed money for current house will be
//    the sum of money in current house and 2 last house.
// 3. else the robbed amount in current house would be the sum of money in current and 3rd last house.

// T.C. --> O(N)
// S.C. --> O(1)






// A 2

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






// A 3 

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






// A 4
