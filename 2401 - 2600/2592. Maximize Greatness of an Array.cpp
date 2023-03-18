class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int L = 0;
        int R = 1;
        int res = 0;
        
        while(R < nums.size()){
            if(nums[L] < nums[R]){
                L++;R++;res++;
            }else R++;
            
        }
        return res;
    }
};


