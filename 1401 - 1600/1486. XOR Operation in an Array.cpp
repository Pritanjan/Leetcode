// https://github.com/Pritanjan/time-pass/blob/main/Bit%20Manipulation/Find%20XOR%20of%20numbers%20from%20L%20to%20R.cpp
// Find XOR of numbers from L to R



// A 1

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        for(int i=0; i<n; i++) nums[i] = start + 2*i;
        // for(int i=0; i<n; i++) cout << nums[i] << " ";
      
        int res = 0;
        for(int i=0; i<n; i++) res ^= nums[i]; 
        return res;
    }
};
