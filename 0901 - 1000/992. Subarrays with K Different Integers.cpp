// A 0 - TLE

class Solution {
public:
    int atMostK(vector<int>& arr, int n, int k) {
        int cnt = 0;
        int L = 0, R = 0;
        unordered_map<int, int> ump;

        while (R < n) {
            if (ump.find(arr[R]) == ump.end()) ump[arr[R]] = 0;
            ump[arr[R]]++;

            while (ump.size() > k) {
                ump[arr[L]] = ump[arr[L]] - 1;
                if (ump[arr[L]] == 0) ump.erase(ump[L++]);
            }
            cnt += R - L + 1;
            R++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        return atMostK(arr, n, k) - atMostK(arr, n, k - 1);
    }
};





// A 1 - Sliding Wondow

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> freq1, freq2;
        int L1 = 0, L2 = 0, totalCount = 0;

        // Right pointer of the sliding window iterates through the array.
        for (int R=0; R<nums.size(); R++) {
            freq1[nums[R]]++;
            freq2[nums[R]]++;

            // If the number of distinct elements in the window exceeds k,
            // we shrink the window from the left until we have at most k distinct elements.
            while (freq1.size() > k) {
                freq1[nums[L1]]--;
                if (freq1[nums[L1]] == 0) freq1.erase(nums[L1]);
                L1++;
            }

            // If the number of distinct elements in the window exceeds k-1,
            // we shrink the window from the left until we have at most k-1 distinct elements.
            while (freq2.size() > k - 1) {
                freq2[nums[L2]]--;
                if (freq2[nums[L2]] == 0) freq2.erase(nums[L2]);
                L2++;
            }

            // Update the total count by adding the length of the current subarray.
            totalCount += (L2 - L1);
        }
        return totalCount;
    }
};

// T.C. -- O(N)
// S.C. -- O(N)3






// A 2 

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Array to store the count of distinct values encountered
        vector<int> cnt(nums.size() + 1, 0);

        int totalCnt = 0;
        int L = 0, R = 0;
        int currCnt = 0;

        while (R < nums.size()) {
            // Increment the count of the current element in the window
            if (++cnt[nums[R++]] == 1) {
                // If encountering a new distinct element, decrement K
                k--;
            }

            // If K becomes negative, adjust the window from the left
            if (k < 0) {
                // Move the left pointer until the count of distinct elements
                // becomes valid again
                --cnt[nums[L++]];
                k++;
                currCnt = 0;
            }

            // If K becomes zero, calculate subarrays
            if (k == 0) {
                // While the count of left remains greater than 1, keep
                // shrinking the window from the left
                while (cnt[nums[L]] > 1) {
                    --cnt[nums[L++]];
                    currCnt++;
                }
                // Add the count of subarrays with k distinct elements to the
                // total count
                totalCnt += (currCnt + 1);
            }
        }
        return totalCnt;
    }
};

// T.C. -- O(N)
// S.C. -- O(N)
