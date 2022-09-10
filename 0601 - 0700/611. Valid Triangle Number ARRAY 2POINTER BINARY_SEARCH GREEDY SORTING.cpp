//We fix nums[k], by iterating k in range [2..n-1], the answer is the total number of pairs (nums[i], nums[j]) for each nums[k], (i < j < k), so that nums[i] + nums[j] > nums[k].

//We start with i = 0, j = k - 1

//If nums[i] + nums[j] > nums[k] then:

//There are j-i valid pairs, because in that case, when nums[k] and nums[j] are fixed, moving i to the right side always causes nums[i] + nums[j] > nums[k].

//Try another nums[j] by decreasing j by one, so j -= 1.

//Else if nums[i] + nums[j] <= nums[k] then:

//Because nums[k] is fixed, to make the inequality correct, we need to increase sum of nums[i] + nums[j].

//There is only one choice is to increase nums[i], so i += 1.


// https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += j - i;
                    j -= 1;
                } else {
                    i += 1;
                }
            }
        }
        return ans;
    }
};
