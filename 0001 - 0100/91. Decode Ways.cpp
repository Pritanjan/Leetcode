// A 1 -  Using a 1D DP Array

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int  i=1; i<=n; ++i) {
            if(s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            if(i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};






// A 2 - Top Down DP

class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return topDown(s, 0, memo);
    }

    int topDown(const string& s, int idx, vector<int>& memo) {
        if(idx == s.length()) return 1;
        if(s[idx] == '0') return 0;
        if(memo[idx] != -1) return memo[idx];
        
        int ways = topDown(s, idx + 1, memo);
        if(idx + 1 < s.length() && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            ways += topDown(s, idx + 2, memo);
        }
        return memo[idx] = ways;
    }
};






// A 3 

