// A 0 - TLE

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int minVal = INT_MAX, maxVal = INT_MIN;
                for (int k = i; k <= j; ++k) {
                    minVal = min(minVal, nums[k]);
                    maxVal = max(maxVal, nums[k]);
                }
                if (minVal == minK && maxVal == maxK)
                    ++count;
            }
        }
        return count;
    }
};






// A 1

// maintain a sliding window that only contains elements within the range [minK, maxK].
// For each element A[i] as the rightmost element of the subarray, you update three indices:
// jbad: Index of the last seen element that is either less than minK or greater than maxK.
// jmin: Index of the last seen element equal to minK.
// jmax: Index of the last seen element equal to maxK.
// Iterate through the array A:
// If A[i] is less than minK or greater than maxK, update j = i.
// If A[i] is equal to minK, update jmin = i.
// If A[i] is equal to maxK, update jmax = i.
// At the end of each iteration, count the number of valid subarrays that end at A[i]. 
// The starting element of the subarray can be chosen in the interval [j + 1, min(jmin, jmax)]. 
// Update the result by adding max(0, min(jmin, jmax) - j).

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j = -1;
        int prevMinKIndex = -1;
        int prevMaxKIndex = -1;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < minK || nums[i] > maxK) j = i;
            if(nums[i] == minK) prevMinKIndex = i;
            if(nums[i] == maxK) prevMaxKIndex = i;
            
            ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j);
        }
        return ans;
    }
};


// T.C. O(N)
// S.C. O(1)






// A 2 

class Solution {
public:
    long long getRes(vector<int>& nums, int si, int ei, int minK, int maxK) {
        vector<int> mink, maxk;
        for (int i = si; i <= ei; i++) {
            if (nums[i] == minK) mink.push_back(i);
            if (nums[i] == maxK) maxk.push_back(i);
        }

        long long res = 0;
        for (int i = si; i <= ei; i++) {
            auto a = lower_bound(mink.begin(), mink.end(), i);
            auto b = lower_bound(maxk.begin(), maxk.end(), i);

            if (a == mink.end() || b == maxk.end()) continue;
            int x = *(a);
            int y = *(b);
            int v = max(x, y);
            res += (ei - v + 1);
        }
        return res;
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l = -1, r = -1;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= maxK && nums[i] >= minK) {
                if (l == -1) l = i;
                r = i;
            } else {
                if (l != -1) ans += getRes(nums, l, r, minK, maxK);
                l = -1, r = -1;
                if (nums[i] <= maxK && nums[i] >= minK) {
                    if (l == -1) l = i;
                    r = i;
                }
            }
        }
        if (l != -1) ans += getRes(nums, l, r, minK, maxK);
        return ans;
    }
};
