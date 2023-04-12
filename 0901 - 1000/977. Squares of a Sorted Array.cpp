// APPROACH 1


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};







// APPROACH 2

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int R = n-1;
        vector<int> ans(n);
        int i = 0;
        
        while(L <= R){
            if(abs(nums[L]) < abs(nums[R])){
                ans[i++] = nums[R] * nums[R];
                R--;
            }
            else{
                ans[i++] = nums[L] * nums[L];
                L++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};




// OR


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int R = n-1;
        vector<int> ans(n);
        int i = n-1;
        
        while(L <= R){
            if(abs(nums[L]) < abs(nums[R])){
                ans[i--] = nums[R] * nums[R];
                R--;
            }
            else{
                ans[i--] = nums[L] * nums[L];
                L++;
            }
        }
        return ans;
    }
};







// APPROACH 3
