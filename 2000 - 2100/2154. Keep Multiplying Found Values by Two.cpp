// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size(); i++){
            while(nums[i]== original )
                original = 2*original;
                 
        }
        return  original;
        
        // if(begin(nums), end(nums), orignal)
        //     return findFinalValue(nums, 2*original);
        // return original;
    }
};
