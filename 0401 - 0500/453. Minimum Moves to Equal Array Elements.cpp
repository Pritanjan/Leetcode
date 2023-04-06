// APPROACH 1 [ Think reversely ]

// Insetead 0f increasing n - 1 elements by 1, decrease 1 element by 1.

// So, we need to find how many moves of each element to be decreased by 1 will  be equal to 
// the min number and sum them up. Do some math and the ans will be sum-min * length


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minNum = INT_MAX, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            minNum = min(minNum, nums[i]);
        }
        return sum - minNum * n;
    }
};





// APPROACH 2

