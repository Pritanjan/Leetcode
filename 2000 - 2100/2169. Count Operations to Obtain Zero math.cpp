// https://leetcode.com/problems/count-operations-to-obtain-zero/

class Solution {
public:
    int countOperations(int nums1, int nums2) {
        return nums1 && nums2 ? nums1 / nums2 + countOperations(nums2, nums1 % nums2) : 0;
        
//         int ans = 0;
//         while(1){
//             if(nums1 > nums2)
//                 swap(nums1, nums2);
            
//             if(nums1 == 0)
//                 break;
            
//             ans += nums2/nums1;
//             nums2 %= nums1;
//         }
//         return ans;
    }
};
