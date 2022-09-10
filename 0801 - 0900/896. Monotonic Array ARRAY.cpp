// https://leetcode.com/problems/monotonic-array/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    	
    	// return is_sorted(nums.begin(), nums.end() ) || is_sorted(nums.rbegin(), nums.rend());
    	
        bool decrease = true;
        bool increase = true;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                increase = false;
                
            if(nums[i] < nums[i+1])
                decrease = false;
            
            if(increase == false && decrease == false)
                return false;
        }
        return true;
    }
};
