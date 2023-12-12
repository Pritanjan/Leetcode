// A 1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums1 = 0, nums2 = 0;
        for(auto num : nums){
            auto temp = max( min(nums1,nums2), num );
            
            nums2 = max(nums1,nums2);
            nums1 = temp;
        }
        return (nums1 - 1) * (nums2 - 1);
    }
};






// A 2 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n-2, nums.end());
        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
};


