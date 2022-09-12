// https://leetcode.com/problems/rotate-array/

// Reveral Algorithm 
// https://www.geeksforgeeks.org/array-rotation/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n);
        int i = 0;
        k %= n;
        
        for (int j=n-k; j<n; j++){
            ans[i] = nums[j];
            i++;
        }           
        for(int j=0; j<n-k; j++){
            ans[i] = nums[j];
            i++;
        }
        nums = ans;
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        							// k = 3
        reverse(nums.begin(),nums.end());		         // [1,2,3,4,5]
        reverse(nums.begin(),nums.begin()+k);		        // [3,2,1,4,5]
        reverse(nums.begin()+k,nums.end());			// [1,2,3,5,4] 
    }
};



