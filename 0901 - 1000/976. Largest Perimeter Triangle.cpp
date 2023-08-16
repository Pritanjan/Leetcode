// APPOACH 2 BRUTE FORECE TLE

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxPerimeter = 0;
        
        for(int i=0; i<n-2; ++i) {
            for(int j=i+1; j<n-1; ++j) {
                for(int k=j+1; k<n; ++k) {
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[j] + nums[k] > nums[i] &&
                        nums[k] + nums[i] > nums[j]) {
                        maxPerimeter = max(maxPerimeter, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }        
        return maxPerimeter;
    }
};






// APPROACH 1 GREEEDY

// sort the array in descending order and then iterate through it to find the largest valid triangle perimeter.

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1; i>=2; i--){
            if(nums[i] < nums[i-1] + nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
            
        }
        return 0;
    }
};


// T.C.  --  O(n log n) due to the sorting step.







// APPROACH 3  2 POINTER

// Sort the array in ascending order and then use a two-pointer approach to find the largest valid triangle perimeter.

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-1; i>=2; --i) {
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            
            if(a < b + c) return a + b + c;
        }        
        return 0;
    }
};

// T.C.  --  O(n log n) due to the sorting step.





