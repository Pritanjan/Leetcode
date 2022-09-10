//https://leetcode.com/problems/running-sum-of-1d-array/

//https://leetcode.com/problems/running-sum-of-1d-array/discuss/2326406/C%2B%2B-oror-3-Solution

// APPROACH 1
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for(int i=0; i<nums.size()-1; i++){
            nums[i+1] = nums[i+1] + nums[i];
        }
            
        return nums;
    }
};
//T.C. --> O(n)
//S.C. --> O(1)

// APPROACH 2
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> ans = {nums[0]};
        
        for(int i=1; i<nums.size(); i++){
            ans.push_back(ans.back() + nums[i]);
        }
        return ans;
    }
};

//T.C. --> O(n)
//S.C. --> O(1)

