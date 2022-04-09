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
