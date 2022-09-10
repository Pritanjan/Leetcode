//  https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		
		// APPROACH 2 MAP
		
        map<int, int> m1, m2;
        int n = nums1.size();
        int m = nums2.size();
        
        for(auto i : nums1){
            m1[i]++;
        }
        for(auto i : nums2){
            m2[i]++;
        }
        
        vector<int> v;
        vector<vector<int>> ans;
        
        for(auto it : m1){
            if(m2.find(it.first) == m2.end())
                v.push_back(it.first);
        }
        
        ans.push_back(v);
        
        v.clear();
       
        for(auto it : m2){
            if(m1.find(it.first) == m1.end())
                v.push_back(it.first);
        }
        
        ans.push_back(v);
        return ans;
        
    }
};
