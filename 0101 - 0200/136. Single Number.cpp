// https://leetcode.com/problems/single-number/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()<1)
            return 0;
        else if(nums.size()>1){
             sort(nums.begin(), nums.end());
        
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
                    i++;
                    
                }
           
        }
        return -1;
    }
};


//https://leetcode.com/problems/single-number/discuss/1771654/daily-leetcoding-challenge-february-day-15

