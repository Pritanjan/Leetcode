// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        
        vector<int> v;
        unordered_map<int, int> um;
//        map<int, int> um;  //BOTH WORKS
        
        for(auto i : nums)
            um[i]++;
        
//        for(int i=0; i<n; i++)
//        	um[nums[i]]++:			// same as line 13 & 14
        
        for(auto it : um)
            if(it.second > n/3){
                v.push_back(it.first);
            }
        return v;
        
        
    }
};
