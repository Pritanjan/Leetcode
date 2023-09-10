// Largest subarray with 0 sum
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


// A 0  - Brute Force Approach:
// Use nested loops to generate all subarrays and calculate their sums.
// Keep a count of subarrays with a sum equal to k.
// It is less efficient and
// It has a time complexity of O(N^2), where N is the length of the input array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            int sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};


// OR


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (dp[i] == k) {
                count++;
            }
            for (int j = i - 1; j >= 0; j--) {
                dp[j] += nums[i];
                if (dp[j] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};






// A 1 - Hash Map
// return the total number of subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        unordered_map<int, int> ump;
        int sum = 0;
        int ans = 0;
        ump[sum] = 1;
        
        for(int i=0; i<A.size(); i++){
            sum += A[i];
            if (ump.find(sum - k) != ump.end()) {
                ans += ump[sum - k];
            }
            ump[sum]++;
        }
        return ans; 
    }
};






// A 2  -  Prefix Sum Array Approach:

// Calculate the prefix sum of the input array nums and store it in a separate array prefixSum.
// Initialize a variable count to keep track of the total number of subarrays with a sum of k.
// Iterate through the prefixSum array and, for each element prefixSum[i], calculate the number of subarrays ending at index i with a sum of k. This can be done by counting the number of times prefixSum[i] - k appears in the prefixSum array up to index i.
// Update the count accordingly.
// Return the count as the answer.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        vector<int> v(n+1, 0);

        // Calculate the prefix sum array.
        for(int i=0; i<n; i++) {
            v[i+1] = v[i] + nums[i];
        }

        unordered_map<int, int> ump;
        for(int i=0; i<=n; i++) {
            if(ump.find(v[i] - k) != ump.end()) {
                cnt += ump[v[i] - k];
            }
            ump[v[i]]++;
        }
        return cnt;
    }
};














// return subarrays whose sum equals to k.
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category[]=Arrays&sortBy=submissions
// Company Tags - Amazon Facebook Google Visa

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int A[], int n, long long k)
    {
        int L = 0;
        int R = 0;
        int sum = 0;
        
        while(L < n){
            sum += A[L];
            
            if(sum == k)
                return {R+1, L+1};
            if(sum > k){
                sum = 0;
                R++;
                L = R - 1;
            }
            L++;
        }
        return {-1};
    }
};






