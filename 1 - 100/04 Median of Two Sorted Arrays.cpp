// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

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
