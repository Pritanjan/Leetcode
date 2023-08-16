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





