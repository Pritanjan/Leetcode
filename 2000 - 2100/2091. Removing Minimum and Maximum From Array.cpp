// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 1;
        
        int mi = 0, mx = 0;
        for(int i=1; i<n; i++){
            if(nums[mi] > nums[i]) mi = i;
            if(nums[mx] < nums[i]) mx = i;
        }
        
        int a = min(mi,mx);
        int s = max(mi,mx);
        
        return min({s+1,n-a, n+1+a-s});  
    }
};





