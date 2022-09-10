// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       
       // APPROACH 1 BY SET
	   
	    unordered_set<int> n1, n2;  // IMPLEMENTING UNORDERED_SETUSING HASH TABLE WHERE KEYS ARE HASHED INTO IDICES OF HASH TABLE
//        set<int> n1, n2;
		int n = nums1.size();
        int m = nums2.size();
        
        for(int i=0; i<n; i++){
            n1.insert(nums1[i]);
        }
        for(int i=0; i<m; i++){
            n2.insert(nums2[i]);
        }
        vector<int> v;
        vector<vector<int>> ans;
        
        for(auto i : n1){
            if(n2.find(i) == n2.end())
                v.push_back(i);
        }
        
        ans.push_back(v);
       
	    v.clear();
       
	    for(int i : n2){
            if(n1.find(i) == n1.end())
                v.push_back(i);
        }
        
        ans.push_back(v);
        return ans;
        
    }
};

// Add all elements of both array in a set.
// Then iterate through both array and using find() method, if the element is not found in other set, add it to the answer.
// Do this for both the arrays and return the answer.
