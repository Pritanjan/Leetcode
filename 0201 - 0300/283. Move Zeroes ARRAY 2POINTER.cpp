//https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        
		// Count zero 
        for(int i=0; i<nums.size(); i++){
            count += (nums[i] == 0);
        }
        
        // Make all the non-zero elements their orignal order.
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0)
                ans.push_back(nums[i]);
        }
        
        // Move all zeros to the end
        while(count--){
            ans.push_back(0);
        }
        
		// combine the result        
        for(int i=0; i<nums.size(); i++){
            nums[i] = ans[i];
        }
        
    }
};

// Space Complexity : O(n). 
// Since we are creating the "ans" array to store results

// Time Complexity: O(n).
// However, the total number of operations are sub-optimal. We can achieve the same result in less number of operations.

// If asked in an interview, the above solution would be a good start. You can explain the interviewer(not code) the above and build your base for the next Optimal Solution.



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;   // nonzero
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int notzero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[notzero++] = nums[i];
            }
        }
        
        for(int i=notzero; i<nums.size(); i++)
            nums[i] = 0;
    }
};

//Space Complexity : O(1)O(1). Only constant space is used.

//Time Complexity: O(n)O(n). However, the total number of operations are still sub-optimal. The total operations (array writes) that code does is nn (Total number of elements).
