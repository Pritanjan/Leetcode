// A 1 - Brute Force  - TLE 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cnt0 = 0, cnt1 = 0;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] == 0) cnt0++;
                else cnt1++;
                if (cnt0 == cnt1) maxLength = max(maxLength, j-i+1);
            }
        }
        return maxLength;
    }
};






// A 2 


