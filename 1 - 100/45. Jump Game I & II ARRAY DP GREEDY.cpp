// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        
        int level = 0, i=0, currentMax = 0, nextMax = 0;
        
        while(currentMax+1-i >0){       //nodes count of current level>0
            level++;
            for(;i<=currentMax;i++){    //traverse current level , and update the max reach of next level
                nextMax = max(nextMax, nums[i]+i);
                if(nextMax >=nums.size()-1)
                    return level;       // if last element is in level+1,  then the min jump=level 
            }
            currentMax = nextMax;
        }
        return 0;
        
    }
};
