// APPROACH 1

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







// APPROACH 2

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int sum = 0;
        for(int i=0; i<accounts.size(); i++){
            sum = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            ans = max(ans,sum);
        }
        return ans;
    }
};

