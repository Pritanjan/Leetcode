class Solution {
public:
    bool canJump(vector<int>& nums) {
        // start at the first index
        int curr = 0;
        // keep track of the maximum index we can reach
        int maxIndex = 0;

        while (curr <= maxIndex) {
            // update the maximum index we can reach
            maxIndex = max(maxIndex, curr + nums[curr]);

            // if we can reach the last index, return true
            if (maxIndex >= nums.size() - 1) {
                return true;
            }

            // move to the next index
            curr++;
        }

        // if we can't reach the last index, return false
        return false;
    }
};



class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()<2)
            return true;
        
        int level = 0, i=0, currentMax = 0, nextMax = 0;
        
        while(currentMax+1-i >0){       
            level++;
            for(;i<=currentMax;i++){    
                nextMax = max(nextMax, nums[i]+i);
                if(nextMax >=nums.size()-1)
                    return level;       
            }
            currentMax = nextMax;
        }
        return 0;
        
    }
};



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int tgt = nums.size() - 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] + i >= tgt)
                tgt = i;
        }
        return tgt == 0;
    }
};





