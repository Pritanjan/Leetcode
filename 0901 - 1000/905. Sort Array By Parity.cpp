// A 1

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R){
            if(nums[L] % 2 != 0) {
                swap(nums[L], nums[R]);
                R--;
            }
            else L++;
        }
        return nums;
    }
};






// A 2 

class Solution {
public:
   vector<int> sortArrayByParity(vector<int>& nums) {
       for (int i = 0, j = 0; j < nums.size(); j++)
           if (nums[j] % 2 == 0) swap(nums[i++], nums[j]);
       return nums;
   }
};

// TC = O(N)






// A 3

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2 == 0)
                ans.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2 != 0)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};






// A 4 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while(L < R) {
            while(L < R && nums[L] % 2 == 0) L++;
            while(L < R && nums[R] % 2 != 0) R--;
            if(L < R) {
                swap(nums[L], nums[R]);
                L++;
                R--;
            }
        }
        return nums;
    }
};






// A 5

