// https://leetcode.com/problems/remove-element/

//Approach 1: Two Pointers
//Intuition

//Since this question is asking us to remove all elements of the 
//given value in-place, we have to handle it with O(1) extra 
//space. How to solve it? We can keep two pointers l and i, 
//where l is the slow-runner while i is the fast-runner.

//Algorithm

//When nums[i] equals to the given value, skip this element by
//incrementing i. As long as nums[i] is not equal val nums[i] 
//,we copy nums[i] to nums[l] and increment both indexes at 
//the same time. Repeat the process until i reaches the end 
//of the array and the new length is l

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};

//Time complexity : O(n). 
//Assume the array has a total of nn elements, both l and i
//traverse at most 2n2n steps.

//Space complexity : O(1).
