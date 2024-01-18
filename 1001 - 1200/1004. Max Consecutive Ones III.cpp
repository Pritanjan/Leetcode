// A 1

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOnes = 0; // Maximum consecutive 1's.
        int L = 0;    // Left pointer of the window.
        int zeroCount = 0; // Count of 0's in the current window.

        for (int R=0; R<nums.size(); ++R) {
            if(nums[R] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds k, shrink the window by moving the left pointer.
            while(zeroCount > k) {
                if(nums[L] == 0) {
                    zeroCount--;
                }
                L++;
            }
            // Update maxOnes with the length of the current window.
            maxOnes = max(maxOnes, R-L+1);
        }
        return maxOnes;
    }
};






// A 2 

