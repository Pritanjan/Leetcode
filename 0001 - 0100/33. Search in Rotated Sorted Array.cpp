// APPROACH 1 [ LINEAR SEARCH ]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};





// APPROACH 2 [ BINARY_SEARCH ]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = l + (r-l) / 2;
            if((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])) l = mid + 1;
            else r = mid;
        }
        return l==r &&  nums[l] == target ? l : -1;
    }
};


// OR


// We need to modify the condition to decide whether to go left or right based on whether the mid 
// element is greater or less than the first element of the array.

// If the mid element is greater than the first element of the array, then we know that the 
// left half of the array is sorted, and we can apply binary search on the left half. 
// If the mid element is less than the first element of the array, then we know that the
// right half of the array is sorted, and we can apply binary search on the right half.

// The only exception to this is when the first element of the array is equal to the mid element. 
// In this case, we cannot decide which half is sorted, so we just increment the start index
// and decrement the end index until we find an element that is not equal to the first element.

// Once we have determined which half is sorted, we can apply regular binary search to find 
// the target element.

// T.C. --> O(log n) 



// OR


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, pivot = 0;
        
        // find the index of the smallest element in nums
        while (L < R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] > nums[R]) L = mid + 1;
            else R = mid;
        }

        pivot = L;
        L = 0;
        R = nums.size() - 1;
        
        // determine which subarray target belongs to
        if(target >= nums[pivot] && target <= nums[R]) L = pivot;
        else R = pivot - 1;
        
        // perform binary search on the selected subarray
        return binarySearch(nums, target, L, R);
    }
    
    int binarySearch(vector<int>& nums, int target, int L, int R) {
        while(L <= R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return -1;
    }
};




// APPROACH 3 [ Binary Search with Rotation Point Identification ]

// Identify the rotation point (pivot index) using a binary search.
// Split the array into two sorted subarrays.
// Choose the correct subarray to perform a binary search for the target 


class Solution {
public:        
    int findRotationPoint(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;

        while(L < R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] > nums[R]) L = mid + 1;
            else R = mid;
        }
        return L;
    }

    int search(vector<int>& nums, int target) {
        int rp = findRotationPoint(nums);   // rotationPoint
        int L = 0;
        int R = nums.size() - 1;

        while(L <= R) {
            int mid = L + (R - L) / 2;
            int rm = (mid + rp) % nums.size();  // rotatedMid 

            if(nums[rm] == target) return rm;
            if(nums[rm] < target) L = mid + 1;
            else R = mid - 1;
        }
        return -1;
    }
};




// APPROACH 4 [ Modified Binary Search with Direct Comparison ]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        
        while(L <= R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[L]) {
                if(target >= nums[L] && target < nums[mid]) R = mid - 1;
                else L = mid + 1;
            } 
            else {
                if(target > nums[mid] && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
        }        
        return -1;
    }
};


