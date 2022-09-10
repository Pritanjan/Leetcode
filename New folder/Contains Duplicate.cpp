// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       sort(begin(nums), end(nums)) ;
           for(int i=1;i<nums.size();i++)
               if(nums[i-1]==nums[i])
                   return true;
            return false;
    }
};
