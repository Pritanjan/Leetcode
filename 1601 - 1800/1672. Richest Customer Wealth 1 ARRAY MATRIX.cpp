//https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        int sum ;
        
        for(auto i : accounts){
            sum = 0;
            for(auto j : i){
                sum += j;
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};



