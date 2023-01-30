// Recursive
// Exponential Time Complexity: O(2^N)
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};




// Memoization
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int tribonacciHelper(int n, vector<int> &dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = tribonacciHelper(n-1, dp) + tribonacciHelper(n-2, dp) + tribonacciHelper(n-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return tribonacciHelper(n, dp);
    }
};



// Tabulation
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+3, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};



// Space Optimized
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, d = 0;

        if(n == 0) return a;
        if(n == 1 || n == 2) return 1;

        for(int i=3;i<=n;i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }

        return c;
    }
};
 
