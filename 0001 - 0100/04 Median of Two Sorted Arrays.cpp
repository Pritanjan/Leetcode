// APPROACH 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums2.insert(end(nums2), begin(nums1), end(nums1));
        sort(begin(nums2),end(nums2));        
        int n = nums2.size();
        if(n % 2 != 0) return nums2[(n/2)];
        else return (nums2[(n/2)-1] + nums2[(n/2)])/2.0;
    }
};






// APPROACH 2

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size = (int) (nums1.size() + nums2.size());
        int dst = size / 2;
        bool need_ave = size % 2 == 0;
        int *arr = new int[size];
        int index = 0;
        double result = 0;
        auto iter = nums1.begin();
        for (auto num: nums2) {
            for (; iter != nums1.end();) {
                if (num <= *iter) {
                    arr[index] = num;
                    if (index == dst) {
                        result = need_ave ? (double) (arr[index - 1] + arr[index]) / 2 : arr[index];
                        return result;
                    }
                    index++;
                    break;
                } else {
                    arr[index] = *iter;
                    if (index == dst) {
                        result = need_ave ? (double) (arr[index - 1] + arr[index]) / 2 : arr[index];
                        return result;
                    }
                    index++;
                    iter++;
                }
            }
            if (iter == nums1.end()) {
                arr[index] = num;
                if (index == dst) {
                    result = need_ave ? (double) (arr[index - 1] + arr[index]) / 2 : arr[index];
                    return result;
                }
                index++;
            }
        }
        for (; iter != nums1.end(); iter++) {
            arr[index] = *iter;
            if (index == dst) {
                result = need_ave ? (double) (arr[index - 1] + arr[index]) / 2 : arr[index];
                return result;
            }
            index++;
        }
        delete[]arr;
        return result;
    }
};





// APPROACH 3

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        nums.resize(m+n); // resize nums to have enough space for merged elements
        merge(nums1.begin(), nums1.end(), nums2.begin(),nums2.end(),nums.begin());

        if((n + m) % 2 != 0) return nums[(n+m) / 2];
        else return (nums[(n+m) / 2] + nums[(n+m) / 2 - 1]) / 2.0; // use 2.0 to avoid integer division
    }
};


// OR


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
        
        int n = merged.size();
        if(n % 2 == 0) return (double)(merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        else return (double)merged[n / 2];
    }
};






// A4 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();        
        
        if(m > n) return findMedianSortedArrays(nums2, nums1);        
        int L = 0, R = m;
        
        while(L <= R) {
            int partitionX = (L + R) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if(maxX <= minY && maxY <= minX) {
                if((m + n) % 2 == 0) return (double)(max(maxX, maxY) + min(minX, minY)) / 2.0;
                else return (double)max(maxX, maxY);
            }
            else if(maxX > minY) R = partitionX - 1;
            else L = partitionX + 1;
        }
        retunrn -1;
    }
};

// explain -  post






// A5

// Merge the two sorted arrays into a single array.
// Calculate the median based on the merged array.
    
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged(m + n);
        
        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) merged[k++] = nums1[i++];
            else merged[k++] = nums2[j++];
        }
        
        while(i < m) merged[k++] = nums1[i++];
        while(j < n) merged[k++] = nums2[j++];
        
        int size = m + n;
        if(size % 2 == 0) {
            int mid1 = merged[(size - 1) / 2];
            int mid2 = merged[size / 2];
            return (double)(mid1 + mid2) / 2;
        } 
        else return (double)merged[size / 2];
    }
};






// A6

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        
        int imin = 0, imax =  m;
        int halfLen = (m+n+1) / 2;
        
        while(imin <= imax) {
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            
            // Increase i to make the left part of nums1 bigger.
            if(i < m && nums2[j-1] > nums1[i]) imin = i + 1;
            // Decrease i to make the left part of nums1 smaller.
            else if(i > 0 && nums1[i-1] > nums2[j]) imax = i - 1;
            else {
                int maxLeft, minRight;
                if(i == 0) maxLeft = nums2[j-1];
                else if(j == 0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                                
                if((m + n) % 2 == 1) return maxLeft;

                if(i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return -1;    
        // This should never be reached if the input arrays are sorted properly.
    }
};






















// K-th element of two sorted Arrays
// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int merged[n + m];
        int i = 0, j = 0, idx = 0;
        
        while(i < n && j < m) {
            if(arr1[i] < arr2[j]) merged[idx++] = arr1[i++];
            else merged[idx++] = arr2[j++];
        }

        while(i < n) merged[idx++] = arr1[i++];
        while(j < m) merged[idx++] = arr2[j++];
        if(k <= n + m) return merged[k - 1];
        
        return -1; // Handle the case when k is out of bounds.
    }
};
