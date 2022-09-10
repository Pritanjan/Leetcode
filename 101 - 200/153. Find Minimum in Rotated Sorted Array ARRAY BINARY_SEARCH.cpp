//Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.
//
//If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; 
        int r = nums.size() - 1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[l] < nums[r])
                return nums[l];
            
            if(nums[l] <= nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};
