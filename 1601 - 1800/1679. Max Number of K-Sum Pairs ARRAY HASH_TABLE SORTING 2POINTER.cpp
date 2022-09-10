//https://leetcode.com/problems/max-number-of-k-sum-pairs/

//we are using the sort function so time complexity will be O(N(Log(N))) but space complexity will be constant O(1);
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int L = 0;
        int R = nums.size() - 1;
        int count = 0;
        
        while(L < R){
            if(nums[L] + nums[R] == k){
                count++;
                L++;
                R--;
            }
            if(nums[L] + nums[R] > k){
                R--;
            }
            if(nums[L] + nums[R] < k){
                L++;
            }
                
        }
        return count;
    }  
};
