// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int i = 0;
        while(nums[i] < nums[i+1])
            i++;
        
        return i;
    }
};

// Approach 1: Linear Scan
// Intuition and Algorithm
//
// The mountain increases until it doesn't. The point at which it stops increasing is the peak
// Time Complexity: O(N), where N is the length of Array.


