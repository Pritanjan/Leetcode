// APPROACH 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums2.insert(end(nums2), begin(nums1), end(nums1));
        
        sort(begin(nums2),end(nums2));
        
        int n = nums2.size();
        if(n%2!=0)
            return nums2[(n/2)];
        else
            return (nums2[(n/2)-1] + nums2[(n/2)])/2.0;
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

        if( (n+m)%2 != 0 )
            return nums[(n+m)/2];
        else 
            return (nums[(n+m)/2] + nums[(n+m)/2-1])/2.0; // use 2.0 to avoid integer division
    }
};

