// https://leetcode.com/problems/majority-element/

APPROACH 1

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int count = 0;
        
        // for(auto i : nums){
        for(int i=0; i<nums.size(); i++){
            
            if(count == 0)
                maj = nums[i];
            
            if(maj == nums[i])
                count++;
            else
                count--;
        }
        return maj;
    }
};


APPROACH 2

    class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};



