// APPROACH 1

class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int mx = 0;
        int jump = 0;
        int currentMax = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            // Update the farthest reachable index of this jump.
            mx = max(mx, nums[i]+i);
            
            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if(i == currentMax){
                jump++;
                currentMax = mx;
            }
            if(i >= mx)
                return -1;
        }
        return jump;
    }
};

// Time complexity : O(n)
// We iterate over nums and stop at the second last element. In each step of the iteration,
// we make some calculations that take constant time. 

// Space complexity: O(1)
// In the iteration, we only need to update three variables, curEnd, curFar and answer, they only
// take constant space



// APPROACH 2

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int L = 0;
        int R = 0;
        int n = nums.size() ;
        while(R < n - 1){
            jump++;
            int mx = R + 1;
            for(int i=L; i<=R; i++){
                if(i + nums[i] >= n){
                    return jump;
                }
                mx = max(mx,i + nums[i]);
            }
            L = R + 1;
            R = mx;
        }
        return jump;
    }
};


// APPROACH 3

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





