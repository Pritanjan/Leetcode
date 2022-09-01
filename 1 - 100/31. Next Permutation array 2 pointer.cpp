// https://leetcode.com/problems/next-permutation/submissions/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	// approach 1
        // next_permutation(nums.begin(), nums.end());
        
        // approach 2
        int n = nums.size();
        int i,j;
        for(i=n-2; i>=0; i--){
            if(nums[i+1] > nums[i])
                break;
        }
        
        if(i < 0){
            reverse(nums.begin(), nums.end() );
        }
        
        else{
            for(j=n-1; j>=0; j--){
                if(nums[j] > nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
            
       
    }
};
