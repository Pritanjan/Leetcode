// A 1 

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0;
        int res = 0;
        int streak = 0;

        for (auto num : nums) {
            if (mx < num) {
                mx = num;
                res = streak = 0;
            }
            if (mx == num)
                streak++;
            else
                streak = 0;
            res = max(res, streak);
        }
        return res;
    }
};
