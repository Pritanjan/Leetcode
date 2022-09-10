//https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(um[k - nums[i]] > 0){
                um[k - nums[i]]--;    // as we have used one pair so we are deleting it
                count++;            //if element found in hashmap increase count 
            }
            else
                um[nums[i]]++;  //if element is not present in map then add the current element
        }
        return count;
    }
};
