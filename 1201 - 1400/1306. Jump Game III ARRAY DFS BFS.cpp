// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        if(nums[start] == -1) // if we visited that value
            return false;
        if(!nums[start])      // if nums[start] == 0
            return true;
        
        int left  = start - nums [start];
        int right = start + nums [start];
        
        nums[start] = -1;  // as start from this
        
        return (right < nums.size() && canReach(nums, right) || (left>=0 && canReach(nums, left)));
         
    }
};


//1. First let's think of edge case when our starting location and destination are same. well this is the best case scenerio so we just return true.
//2. From the intuition we know we have to jump left and right ,so before jumping we need to check if we have already been there or not . Thus to mark the visited locations we mark them as -1
//3. arr[start] should be marked as visited yup, you guessed it correctly , since we start form arr[start] it should be marked as -1
//4. Now if righside is less then arr.size() then do the rightside recursion or if leftside is > 0 then we have to do leftside recursion .

