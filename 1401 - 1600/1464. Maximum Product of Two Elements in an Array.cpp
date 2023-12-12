// A 0 - Brute Force

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
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

// T.C. --> O(log N)
// S.C. --> O(log N)






// A 3  - Priority Queue

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int max1 = pq.top(); pq.pop();
        int max2 = pq.top(); pq.pop();
        return (max1 - 1) * (max2 - 1);
    }
};






// A 4  - Find Maximums

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = *max_element(nums.begin(), nums.end());
        nums.erase(max_element(nums.begin(), nums.end()));
        int max2 = *max_element(nums.begin(), nums.end());
        return (max1 - 1) * (max2 - 1);
    }
};






// A 5 - DP 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for(int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                dp[j] = max(dp[j], (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


