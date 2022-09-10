// https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        unordered_map <int,int> ump;
        int sum = 0;
        int ans = 0;
        
        while(r < nums.size() ){
            int rt = nums[r++];
            sum += rt;
            ump[rt]++;
            
            while(ump[rt] > 1){
                int lt = nums[l++];
                ump[lt]--;
                sum -= lt;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};

Keep a frequency map of the numbers in the window.

while the count of the latest number in the window is greater than 1, shrink the window.

record the best answer.
