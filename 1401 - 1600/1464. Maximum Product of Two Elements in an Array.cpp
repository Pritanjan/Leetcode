// A 0

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }        
        return ans;
    }
};

// T.C. --> O(N^2)
// S.C. --> O(1)






// A 1 - Track Second Biggest

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

// T.C. --> O(N)
// S.C. --> O(1)






// A 2 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n-2, nums.end());
        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
};


// OR
// STL - SORT


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums[nums.size() - 1];
        int y = nums[nums.size() - 2];
        return (x - 1) * (y - 1);
    }
};

// T.C. --> O(log N)
// S.C. --> O(log N)





