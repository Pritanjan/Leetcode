// https://leetcode.com/problems/majority-element-ii/
// https://leetcode.com/problems/majority-element/
// Similar question LC 169
// https://github.com/Pritanjan/Leetcode/edit/main/0101%20-%200200/169.%20Majority%20Element%20ARRAY%20HASH_TABLE%20DIVIDE_AND_CONQUER%20SORTING%20COUNTING.cpp

// https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027?leftPanelTab=0

// APPROACH 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        
        vector<int> v;
        unordered_map<int, int> um;
//         map<int, int> um;  //BOTH WORKS
        
        for(auto i : nums)
            um[i]++;
        
//        for(int i=0; i<n; i++)
//        	um[nums[i]]++:			// same as line 41 & 42
        
        for(auto it : um)
            if(it.second > n/3){
                v.push_back(it.first);
            }
        return v;
    }
};
