class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        for (int s = 0; s <= n - k; s++) {
            bool isConsAndSorted = true;
            for (int idx = s; idx < s + k - 1; idx++) {
                if (nums[idx + 1] != nums[idx] + 1) {
                    isConsAndSorted = false;
                    break;
                }
            }
            if (isConsAndSorted) res[s] = nums[s + k - 1];
            else res[s] = -1;
        }
        return res;
    }
};
