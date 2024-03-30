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
