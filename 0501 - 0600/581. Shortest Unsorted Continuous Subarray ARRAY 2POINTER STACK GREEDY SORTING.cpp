// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

//Create a new vector v same as nums.
//Sort the vector v.
//Move the L pointer from the left  to check index till where the v vector is sorted from left side.
//Move the R pointer from the right to check index till where the v vector is sorted from right side.
/////If i==n return 0 i.e. vector is sorted.
//else return j-i+1.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int L = 0;
        int R = nums.size() - 1;
        
        while(L < nums.size() && nums[L] == v[L])
            L++;
        while(R > L && nums[R] == v[R])
            R--;
        
        return R - L + 1;
    }
};
