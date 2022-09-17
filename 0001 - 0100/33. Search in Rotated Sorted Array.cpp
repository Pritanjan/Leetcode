// https://leetcode.com/problems/search-in-rotated-sorted-array/


// APPROACH 1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target )
                return i;
        }
        return -1;
    }
};


// APPROACH 2 BINARY_SEARCH 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r){
            int mid = l + (r-l) / 2;
            if((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                l = mid + 1;
            else
                r = mid;
        }
        return l==r &&  nums[l] == target ? l : -1;
    }
};




