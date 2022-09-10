// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int d = nums[1] - nums[0];
        // bool flag = true;
        int flag = 1;
        for(int i=0; i<nums.size() - 1; i++){
            if( nums[i+1] - nums[i] == d){
                // flag = 1;
                continue;
            }
 
            else{
                flag = 0;
                break;
            }
            
            
        }
        
        if(flag == 1)
            return true;
        else
            return false;
    }
};
