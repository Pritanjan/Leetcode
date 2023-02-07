// APPROACH 1

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R){
            if(nums[L] % 2 != 0){
                swap(nums[L], nums[R]);
                R--;
            }
            else 
                L++;
        }
        return nums;
    }
};


// APPROACH 2 

class Solution {
public:
   vector<int> sortArrayByParity(vector<int>& nums) {
       for (int i = 0, j = 0; j < nums.size(); j++)
           if (nums[j] % 2 == 0) swap(nums[i++], nums[j]);
       return nums;
   }
};

// TC = O(N)


// APPROACH 3

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0)
                ans.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
