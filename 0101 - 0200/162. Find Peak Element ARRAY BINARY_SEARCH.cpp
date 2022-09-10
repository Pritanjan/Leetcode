//https://leetcode.com/problems/find-peak-element/solution/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int L = 0;
        int R = nums.size()-1;
        
        while(L < R){
            int mid = L + (R-L)/2;
            
            if(nums[mid] > nums[mid+1])
                R = mid;
            else
                L = mid + 1;
        }
        return L;
    }
};

//Time complexity : O(log_2(n). We reduce the search space in 
//half at every step. Thus, the total search space will be 
//consumed in log_2(n)steps. Here,n refers to the size of array.

//Space complexity : O(1). Constant extra space is used.
