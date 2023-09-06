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







// A5 - Recursion

class Solution {
public:
    int recursion(vector<int>& nums, int target, int L, int R) {
        if(L > R) return -1;
        int mid = L + (R - L) / 2;
        if(nums[mid] == target) return mid;
        if(nums[L] <= nums[mid]) {  // Left half is sorted
            if(nums[L] <= target && target < nums[mid]) return recursion(nums, target, L, mid - 1);
            else return recursion(nums, target, mid + 1, R);
        }
        else {  // Right half is sorted
            if(nums[mid] < target && target <= nums[R]) return recursion(nums, target, mid + 1, R);
            else return recursion(nums, target, L, mid - 1);
        }
    }

    int search(vector<int>& nums, int target) {
        return recursion(nums, target, 0, nums.size() - 1);
    }
};


// OR


class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto L = nums.begin();
        auto R = nums.end() - 1;
        while(L <= R) {
            auto mid = L + ((R - L) >> 2);

            if(*mid == target) return distance(nums.begin(), mid);
            if(*L <= *mid) {
                if(target >= *L && target < *mid) R = mid - 1;
                else L = mid + 1;
            } 
            else {
                if(target > *mid && target <= *R) L = mid + 1;
                else R = mid - 1;
            }
        }
        return -1; 
    }
};






// A 6  -  STL

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if(it != nums.end()) return distance(nums.begin(), it);
        return -1;
    }
};






// A 7 using pivot & binary search
// Find the pivot index using distance and then perform binary search to find the target element.

// distance STL is used to find the pivot index (the index of the smallest element) and \
// then perform a binary search in the rotated sorted array. 
// We adjust the mid-point index to account for the rotation by adding pivotIdx and
// taking the modulo operation to wrap around the array

// T.C. - O(log N)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Empty array, target not found
        if(nums.empty()) return -1; 

        // Find the pivot index using distance
        int pivotIdx = distance(nums.begin(), min_element(nums.begin(), nums.end()));

        // Perform binary search
        int L = 0;
        int R = nums.size() - 1;

        while(L <= R) {
            int mid = L + (R - L) / 2;
            int rotatedMid = (mid + pivotIdx) % nums.size();
            if(nums[rotatedMid] == target) return rotatedMid;
            if(nums[rotatedMid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return -1; 
    }
};






// A 8
