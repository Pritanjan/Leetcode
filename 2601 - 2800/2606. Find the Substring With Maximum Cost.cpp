class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> ump;
        
        for(int i=0; i<chars.size(); i++) ump[chars[i]] = vals[i];
        
        int n = s.size();
        vector<int> dp(n+1, 0);        

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(ump.find(s[i-1]) != ump.end()) dp[i] = max(dp[i-1] + ump[s[i-1]], 0);
            else dp[i] = max(dp[i-1] + s[i-1] - 'a' + 1, 0);
            
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};




