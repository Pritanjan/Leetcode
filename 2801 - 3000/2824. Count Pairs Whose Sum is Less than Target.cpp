// APPROACH 1  Brute Force
// use a nested loop to check all possible pairs and count the ones that satisfy the condition.

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(nums[i] + nums[j] < target) cnt++;
            }
        }        
        return cnt;
    }
};





// APPROACH 2  2 Pointer

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int L = 0, R = n - 1;
        while(L < R) {
            if(nums[L] + nums[R] < target) {  
                cnt += R - L;
                L++;
            } 
            else R--;
        }
        return cnt;
    }
};

