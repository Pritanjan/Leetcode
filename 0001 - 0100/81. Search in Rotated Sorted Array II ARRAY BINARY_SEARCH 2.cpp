// APPROACH 1 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target)
                return true;
        }
        return false;
    }
};






// APPROACH 2

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





// APPROACH 3

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


