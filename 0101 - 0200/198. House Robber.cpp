// A 1

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev1 = 0, prev2 = 0;
        int temp = 0;
        
        for(int i=0; i<nums.size(); i++) {
            temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1 ;
            prev1 = temp;
        }
        return temp;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)






// A 2

class Solution {
public:
    int rob(vector<int>& nums) {
        int h1 = 0, h2 = 0, h3 = 0;
        int temp = 0;
        
        for(int i=0; i<nums.size(); i++) {
            temp = nums[i] + max(h2,h3) ;
            h3 = h2;
            h2 = h1;
            h1 = temp;
        }
        return max(h1,h2);
    }
};


//C++ solution (time taken : 0ms, time complexity O(n), Space Complexity O(1) )
//
//Used 3 variables to store the amount of money the robber have if robbed in previous three houses;
//for the current house the amount will be the either :
//
//if robbed amount in 2 last house is more than 3rd last then robbed money for current house will be the sum of money in current house and 2 last house.
//else the robbed amount in current house would be the sum of money in current and 3rd last house.
