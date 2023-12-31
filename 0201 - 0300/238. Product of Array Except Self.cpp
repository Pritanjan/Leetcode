// A 1 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        vector<int> prod(n);
        
        for(int i = 0; i<n; i++){
            prod[i] = prefix;
            prefix*=nums[i];
        }
        
        for(int i=n-1; i>=0; i--){
            prod[i]*=suffix;
            suffix*=nums[i];
        }
        
        return prod;
    }
};






// A 2 

