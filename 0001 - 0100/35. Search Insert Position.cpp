// APPROACH 1 [ BINARY SEARCH ]

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




// T.C. -->  O(log N)



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







// APPROACH 4

class Solution {
public:
    int f(vector<int>& nums, int& target, int l, int r){
        if(l >= r) return nums[l] >= target ? l : l + 1;
        int mid = l + ((r - l) >> 1);
        return nums[mid] == target ? mid : nums[mid] > target ? f(nums,target,l,mid-1) : f(nums,target,mid+1,r);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return f(nums,target,0,(int)nums.size()-1);
    }
};







// APPROACH 5

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1) {
            if(target <= nums[0]) return 0;
            else return 1;
        }

        if(target < nums[0]) return 0;
        if(target > nums[size-1]) return size;
        
        for(int i=0; i<size; ++i){
            if(nums[i] == target) return i;
            else if (nums[i] != target && nums[i+1] > target) return i+1;
        }
        return -1;
    }
};



