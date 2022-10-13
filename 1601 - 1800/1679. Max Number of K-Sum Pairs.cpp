//https://leetcode.com/problems/max-number-of-k-sum-pairs/

// Approach 1: Brute force approach Time complexty is o(logn) space complexty is O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int L = 0;
        int R = nums.size() - 1;
        int count = 0;
        
        while(L < R){
            if(nums[L] + nums[R] == k){
                count++;
                L++;
                R--;
            }
            if(nums[L] + nums[R] > k){
                R--;
            }
            if(nums[L] + nums[R] < k){
                L++;
            }
                
        }
        return count;
    }  
};


// Approach 2:Optimize approach Time complexty is O(n) space complexty is O(n) because we are using map

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(um[k - nums[i]] > 0){
                um[k - nums[i]]--;    // as we have used one pair so we are deleting it
                count++;              // if element found in hashmap increase count 
            }
            else
                um[nums[i]]++;        // if element is not present in map then add the current element
        }
        return count;
    }
};
