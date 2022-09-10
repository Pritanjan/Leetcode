//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        for(int i=0; i<nums1.size(); i++){
            int p = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() ;
            for(int j=p+1; j<nums2.size(); j++){
                if(nums1[i] < nums2[j]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};
