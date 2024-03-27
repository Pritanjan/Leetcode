// A 1 - Brute Force

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int pdt = 1;
            for(int j=i; j<n; j++) {
            // for(auto j : nums) {
                pdt *= nums[j];
                if(pdt < k) cnt++;
                else break;

                cout << pdt << endl;
            }
        }
        return cnt;
    }
};






// A 2 - Sliding Window

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Handle edge cases where k is 0 or 1 (no subarrays possible)
        if (k <= 1) return 0;

        int cnt = 0;
        int pdt = 1;

        // Use two pointers to maintain a sliding window
        for (int L = 0, R = 0; R < nums.size(); R++) {
            // Expand the window by including the element at the right pointer
            pdt *= nums[R];

            // Shrink the window from the left while the product is greater than
            // or equal to k
            while (pdt >= k) {
                // Remove the element at the left pointer from the product
                pdt /= nums[L++];
            }

            // Update the total count by adding the number of valid subarrays
            // with the current window size
            cnt += R - L + 1;
            // right - left + 1 represents the current window size
        }
        return cnt;
    }
};

