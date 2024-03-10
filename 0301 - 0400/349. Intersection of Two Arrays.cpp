// A 1 - Brute Force 

// Iterate through each element of the first array.
// For each element, iterate through the second array to check for intersection.
// Time complexity: O(n*m), where n and m are the lengths of the arrays.
    
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

// Here s.erase(x) will use binary search to find element and 
// erase all occurances of element if found. 
// Hence you see tag "Binary Search"






// A 2 - Sorting and Two Pointers:

// Sort both arrays.
// Use two pointers to iterate through both arrays and identify common elements.
// T.C. --> O(nlog(n) + mlog(m) + n + m), where n and m are the lengths of the arrays.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                if(res.empty() || res.back() != nums1[i]) res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
