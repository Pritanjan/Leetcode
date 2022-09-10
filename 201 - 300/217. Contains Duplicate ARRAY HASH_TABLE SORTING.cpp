//https://leetcode.com/problems/contains-duplicate/

// Approach 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            if(nums[i-1]==  nums[i]) 
                return true;
            return false;
        }
};

// Approach 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> us;
        for(auto i : nums)
            us.insert(i);
        
        return us.size() != nums.size();
    }
};
