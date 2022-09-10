//349. Intersection of Two Arrays
//https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            if(s1.erase(nums2[i]))
                ans.push_back(nums2[i]);
        }
        return ans;
    }
};

// Here s.erase(x) will use binary search to find element and erase all occurances of element if found. Hence you see tag "Binary Search"


