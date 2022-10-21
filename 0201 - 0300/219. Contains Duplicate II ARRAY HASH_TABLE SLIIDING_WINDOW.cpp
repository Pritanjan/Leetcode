//https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set <int> us;
        
        for(int i=0; i<nums.size(); i++){
            if(i > k)
                us.erase(nums[i-k-1]);
            if(us.find(nums[i]) != us.end())
                return true;
            
            us.insert(nums[i]);
        }
            
        
        return false;
    }
};


// The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1],
// if nums[i] is in set s then return true else update the set.



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> ump;
        for(int i=0; i<nums.size(); i++){
            if(ump.count(nums[i]) == 0)
                ump[nums[i]] = i;
            else if (i - ump[nums[i]] <= k)
                return true;
            else
                ump[nums[i]] = i;
        }
        return false;
    }
};
