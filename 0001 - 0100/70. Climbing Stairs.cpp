// A 1

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int a = 1, b = 2;
        for(int i=3; i<n; i++){
            int t = a + b;
            a = b;
            b = t;
        }
        return a + b;
    }
};






// A 2 - DP (Bottom-Up)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }        
        return dp[n];
    }
};






// A 3

