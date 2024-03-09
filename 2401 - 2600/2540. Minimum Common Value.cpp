// A 1 -  Using Two Pointers

class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                return a[i];
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
};






// A 2 - Using Hash Set

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Add the elements from nums1 to set1
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Search for each element of nums2 in set1
        // Return the first common element found
        for (int num : nums2) {
            if (set1.contains(num)) {
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
};






// A 3 - STL

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v));
        if(!v.empty()) {
            return v[0]; // Return the first common element
        }
        return -1; // No common element found
    }
};







// A 4 

class Solution {
public:
    int binarySearch(std::vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (nums[mid] == target) {
                return mid; // Found the target
            } else if (nums[mid] < target) {
                L = mid + 1; // Search in the right half
            } else {
                R = mid - 1; // Search in the left half
            }
        }
        return -1; // Target not found
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Iterate through nums1 and perform binary search on nums2
        for (int num : nums1) {
            if (binarySearch(nums2, num) != -1) {
                return num; // Found common element
            }
        }
        return -1; // No common element found
    }
};
