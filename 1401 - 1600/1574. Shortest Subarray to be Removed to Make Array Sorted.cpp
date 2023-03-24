// APPROACH 1

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        
        // Find the longest non-decreasing prefix
        while (left < n - 1 && arr[left] <= arr[left + 1]) left++;
        
        // The array is already non-decreasing
        if (left == n - 1) return 0;
        
        // Find the longest non-increasing suffix
        while (right > 0 && arr[right] >= arr[right - 1]) right--;
        
        // Remove either the prefix or suffix
        int result = min(n - left - 1, right);
        
        // Remove a subarray in the middle
        for(int i=0, j=right; i<=left && j<n; ) {
            if(arr[i] <= arr[j]) {
                i++;
                result = min(result, j - i);
            } else {
                j++;
            }
        }
        
        return result;
    }
};







// APPROACH 2

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) i++;
        if (i == n - 1) return 0;
        while (j - 1 >= 0 && arr[j] >= arr[j - 1]) j--;
        if (j == 0) return 0;

        // Interval [0,i] and interval [j, n) are incremented
        int ans = j;
        for (int k = 0; k <= i; k++) {
            int idx = low_bound(j, n - 1, arr, arr[k]);
            ans = min(ans, idx - k - 1);
        }
        return ans;
    }

private:
    int low_bound(int left, int right, const vector<int> &arr, int target) {
        if (target <= arr[left]) return left;
        if (target > arr[right]) return right + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};






