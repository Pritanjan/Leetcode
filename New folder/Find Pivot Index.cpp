class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        // for(int i=0; i<nums.size(); i++){
            // ans += nums[i];
        // }
        
        for(auto i : nums){
            ans += i;
        }
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
            if(sum * 2 == ans + nums[i] )
                return i;
        }
        return -1;
        
    }
};
