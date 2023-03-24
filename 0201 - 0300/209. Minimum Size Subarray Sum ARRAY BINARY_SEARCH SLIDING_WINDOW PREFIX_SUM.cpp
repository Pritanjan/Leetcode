// APPROACH 1
// APPROACH 1

// 1. Initialize 2 pointer, L to 0 and sum to 0
// 2. Iterate over the nums and add nums[i] to sum
// 3. while sum is greater than or equal to target
//     update ans = min(ans, i+1-L), where i+1-L is the size of current subarray
//     it means that the first index can safely be incermented, since the minimum subarray with this index with sum greater or equal to target has been achieved .
//     subtract nums[L] from sum and then increment L 


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int L = 0;
        int sum = 0;
        int i = 0;
        
        while(n--)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans, i+1-L);
                sum -= nums[L++];
            }
            i++;
        }
        
        return (ans == INT_MAX) ? 0 : ans;
    }
};





// The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s,
// then we move l to the right until sum < s. In this process, store the minimum length 
// between l and r. Since each element in nums will be visited by l and r for at
// most once. 







// APPROACH 2 (using binary search)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        
        for(int i=1; i<=n; i++) sums[i] = sums[i - 1] + nums[i - 1];
        
        for(int i=1; i<=n; i++) {
            int to_find = target + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if(bound != sums.end())  ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

// Time complexity: O(n log n)
// Space complexity: O(n)
    

