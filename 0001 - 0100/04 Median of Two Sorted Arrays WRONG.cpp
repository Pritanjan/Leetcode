/ https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        // nums=n+m;
       // nums = nums1.merge(nums2) ;
        merge(nums1.begin(), nums1.end(), nums2.begin(),nums2.end(),nums.begin());
        //  merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
        if( (n+m)%2 !=0 )
            // cout<<nums[(n+m/2)+1] << endl;
            return nums[(n+m/2)+1] ;
        else 
             // cout<<(nums[(n+m/2)+1] + nums[(n+m/2)] )/2 << endl;
            return (nums[(n+m/2)+1] + nums[(n+m/2)] )/2 ;
        
    }
};

