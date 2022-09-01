// https://leetcode.com/problems/remove-element/

//Algorithm
//
//When we encounter nums[i] = valnums[i]=val, we can swap the current element out with the last element and dispose the last one. This essentially reduces the array's size by 1.
//
//Note that the last element that was swapped in could be the value you want to remove itself. But don't worry, in the next iteration we will still check this element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return n;
    }
};

//Complexity analysis
//
//Time complexity : O(n)O(n). Both ii and nn traverse at most nn steps. In this approach, the number of assignment operations is equal to the number of elements to remove. So it is more efficient if elements to remove are rare.
//
//Space complexity : O(1)O(1).
