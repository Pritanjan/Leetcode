// APPROACH 1


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        int n = nums.size();

        return  max((nums[0] * nums[1] * nums[n-1]), (nums[n-1] * nums[n-2] * nums[n-3]) );
    }
};







// APPROACH 2

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int i : nums) {
            if (i <= min1) {
                min2 = min1;
                min1 = i;
            } else if (i <= min2) {
                min2 = i;
            }
            if (i >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = i;
            } else if (i >= max2) {
                max3 = max2;
                max2 = i;
            } else if (i >= max3) {
                max3 = i;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};







