//https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i=0; i<nums.size(); i++){
            ans += ((i+1)*(n-i) +1)/2 * nums[i];
        }
        return ans;
    }
};







// (i+1)*(n-i) --> toatal no. of subarray 
// (i+1)*(n-i) / 2  no. of odd subarray 

// T.C. = O(n)

