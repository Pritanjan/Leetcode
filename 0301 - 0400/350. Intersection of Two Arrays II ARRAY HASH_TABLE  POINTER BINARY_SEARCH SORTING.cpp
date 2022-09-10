// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s;
        
        for(int i : nums1)
            s[i]++;
        
//        for(int i = 0; i < nums1.size(); i++)
//           map[nums1[i]]++;
        
        
        vector<int> ans;
		
//		for(int i = 0; i < nums2.size(); i++)
//        {  
//            if(map[nums2[i]] >= 1) {
//                ans.push_back(nums2[i]);
//                map[nums2[i]]--;   
//            }
//        }
//        
		
        for(int i : nums2){ 
            if(s[i]-- > 0)
                ans.push_back(i);
        }
        return ans;
    }
};
