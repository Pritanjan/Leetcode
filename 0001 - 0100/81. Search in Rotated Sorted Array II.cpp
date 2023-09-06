// A 1 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) return true;
        }
        return false;
    }
};






// A 2 [ Binary Search with 2 Popinter ]

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left  = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
           int mid = (left + right)/2;
           if(nums[mid] == target) return true;
           if(nums[mid] >= nums[left]) {
               if(target <  nums[mid] && target >= nums[left]) right = mid - 1;
               else left = mid + 1;
           }
           else if(nums[mid] < nums[left]) {
               if(target >  nums[mid] && target <= nums[left]) left = mid + 1;
               else right = mid - 1;
            }
            else left++;       
        }
        return false;
    }
};


// OR
// modify  binary search algorithm to handle the rotated array. 

// Steps -
// - Use two pointers, L and R, to define the search range.
// - Calculate the middle index mid between L and R.
// - Compare the mid element with the target element.
// - If the mid element equals the target, return true.
// - If the L half is sorted (nums[L] <= nums[mid]), check if the target falls within the sorted
//   range. If it does, update R = mid - 1; otherwise, update L = mid + 1.
// - If the right half is sorted (nums[mid] <= nums[R]), check if the target falls within
//   the sorted range. If it does, update L = mid + 1; otherwise, update R = mid - 1.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        while(L <= R) {
            int mid = L + (R-L) / 2;
            if(nums[mid] == target) return true;            
            if(nums[L] == nums[mid] && nums[mid] == nums[R]) {
                ++L;
                --R;
            } 
            else if(nums[L] <= nums[mid]) {
                if(nums[L] <= target && target < nums[mid]) R = mid - 1;
                else L = mid + 1;
            }
            else {
                if(nums[mid] < target && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
        }        
        return false;
    }
};






// A 3 [ Binary Search With Pivot ] LeetCode

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        int R = n - 1;
        int L = 0;

        while(L <= R) {
            int mid = L + (R-L) / 2;
            if(nums[mid] == target) return true;
            if(!isBinarySearchHelpful(nums, L, nums[mid])) {
                L++;
                continue;
            }

            // which array does pivot belong to.
            bool pivotArray = existsInFirst(nums, L, nums[mid]);

            // which array does target belong to.
            bool targetArray = existsInFirst(nums, L, target);
            // If pivot and target exist in different sorted arrays, recall that xor is true only when both the operands are distinct
            if(pivotArray ^ targetArray) { 
                if(pivotArray) L = mid + 1; // pivot in the first, target in the second
                else end = mid - 1; // target in the first, pivot in the second    
            } 
            else { // If pivot and target exist in same sorted array
                if(nums[mid] < target) L = mid + 1;
                else end = mid - 1;
            }
        }
        return false;
    }

    // returns true if we can reduce the search space in current binary search space
    bool isBinarySearchHelpful(vector<int>& nums, int L, int element) {
        return nums[L] != element;
    }

    // returns true if element exists in first array, false if it exists in second
    bool existsInFirst(vector<int>& nums, int L, int element) {
        return nums[L] <= element;
    }
};






// A 4 [ One-Pass Binary Search ]

// The key idea is to adjust the binary search conditions based 
// on the rotated array's characteristics

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;

        while(L <= R) {
            int mid = L + (R-L) / 2;
            if(nums[mid] == target) return true;
            if(nums[L] < nums[mid]) {
                if(nums[L] <= target && target < nums[mid]) R = mid-1;
                else L = mid + 1;
            }
            else if(nums[L] > nums[mid]) {
                if(nums[mid] < target && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
            else ++L;
        }
        return false;
    }
};






// A 5 - STL

// find function perform linear search 
// leess effiecent then binary search

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};






// A 6

