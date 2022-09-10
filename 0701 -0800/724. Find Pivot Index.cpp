class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        
        int current = 0;
        for(int i=0; i<nums.size(); i++){
            if(current == sum - current - nums[i] )
                return i;   
            current += nums[i];
        }
        return -1;
        
    }
};

//T.C. O(n)


//https://leetcode.com/problems/find-pivot-index/discuss/2425048/c-2-solution-with-explanation

