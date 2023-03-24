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



// We first find the longest non-decreasing prefix of the array and 
// the longest non-increasing suffix of the array. 
// If the array is already non-decreasing, we return 0.

// If we remove either the prefix or suffix, the remaining array is non-decreasing. 
// We calculate the length of the subarray to remove as the minimum of the length
// of the prefix and suffix.

// We then consider removing a subarray in the middle of the array.
// We start with the first element of the prefix and the last element
// of the suffix and move towards the middle. 
// If the elements are non-decreasing, we move the left pointer one step to the right
// and update the length of the subarray to remove. 
// Otherwise, we move the right pointer one step to the right.
// We continue until the left and right pointers meet.

// Finally, we return the length of the shortest subarray to remove.


// Time Complexity: O(N). N is the length of an array.
// The solution involves scanning the input array at most three times. 

// Space Complexity: O(1).
// The solution uses a constant amount of extra space for variables. 
   








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



// This approach starts by finding the longest non-decreasing prefix and longest
// non-increasing suffix of the given array. If the array is already non-decreasing 
// or non-increasing, then the answer is 0.

// Next, we iterate through the elements of the prefix (i.e., from index 0 to i) and 
// try to find the position of the smallest element in the suffix that is greater than or
// equal to the current prefix element.
// We use the binary search algorithm to find this position in logarithmic time complexity.

// For each prefix element, we calculate the length of the subarray to be removed 
// if we remove it, such that the remaining elements are non-decreasing. 
// We take the minimum of all such subarray lengths as our answer.

// The time complexity of the algorithm is O(nlogn) due to the binary search operation
// Space complexity is O(1) as we are using a constant amount of extra space for variables.


// Here, the low_bound function is a custom implementation of the binary search algorithm
// to find the first occurrence of the target element in a sorted array. 
// It returns the index of the first element that is greater than or equal to the target element.
// If the target element is not present in the array, it returns the index where the
// target element should be inserted to maintain the sorted order of the array.





