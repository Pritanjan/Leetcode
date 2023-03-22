// APPROACH 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        while(L < R){
            if(nums[L] + nums[R] == target){
                return {L+1, R+1};
            }
            else if(nums[L] + nums[R] > target)
                R--;
            else
                L++;
                
        }
        return {};
    }
};









// APPROACH 2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size()-1; i++){
            int L = i+1;
            int R = nums.size();      
            while(L < R){
                int mid = L + (R - L)/2;
                if(nums[mid] == target - nums[i]) return {i+1, mid+1};
                else if(nums[mid] >= target - nums[i]) R = mid;
                else L = mid + 1;
            }

            if(L != nums.size() and nums[L] == target - nums[i]) return {i+1, L+1};
        }
        
        return {};
    }
};









