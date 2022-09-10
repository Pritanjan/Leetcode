// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        map<int, int> m;
        for(int i : nums)
            m[i]++;
        for(auto it : m)
            if(it.second == 2)
                ans.push_back(it.first);
        
        return ans;
    }
};
