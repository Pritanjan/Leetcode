// APPROACH 1

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 
        while(right >= left) {
            int mid = (left+ right)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid -1;
            else left = mid + 1;
        }
        return left;        
    }    
};

// why to return left ?
// Because when high = low+1, then mid = low.

// If the target > nums[mid], then low = mid + 1 = high. The target position
// can be low or high, since they are the same.

// but if the target < nums[mid], then high = mid - 1 = low - 1. 
// The target position must be low, not the high.





// APPROACH 2

class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        return lower_bound(A.begin(), A.end(), target) - A.begin();
    }
};







// APPROACH 3

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return n;
    }
};


