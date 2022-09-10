// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        
        int L = 1;
        int R = n-2;
        
        while(L <= R){
            // int mid = (L+R)/2;
            int mid = L + (R - L)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] <  nums[mid+1])
                L = mid + 1;
            else
                R = mid - 1; 
            
        }
        
        return -1;
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;
        
        while(L <= R){
            // int mid = (L+R)/2;
            int mid = L + (R - L)/2;
//            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
//                return mid;
            else if(nums[mid] <  nums[mid+1])
                L = mid + 1;
            else
                R = mid ; 
            
        }
        
        return L;
    }
};


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

