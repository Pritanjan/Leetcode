// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = nums.size() * (nums.size() + 1) /2;
        for(int i=0; i<nums.size(); i++){
            sum -= nums[i];
        }
        return sum;    
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans ^= nums[i] ^(i+1);
    }
    return ans;
    }
};



