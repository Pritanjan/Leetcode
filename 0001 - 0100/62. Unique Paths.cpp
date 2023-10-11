// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0060%20230323%20Unique%20Paths%20in%20a%20Grid.cpp

// APPROACH 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp;
        int dp[m][n];
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};






// APPROACH 2  DP

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                // Initialize the edges to 1 since there's only one way to reach them
                if(i == 0 || j == 0) dp[i][j] = 1;
                // Paths from above and left
                else dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        }
        // Number of unique paths to bottom-right corner
        return dp[m-1][n-1]; 
    }
};






// APPROACH 3 . Combinatorics Approach:

class Solution {
public:
    int uniquePaths(int m, int n) {
         int totalSteps = m+n-2;
        // Calculate the number of steps required to move down or right
        int stepsDown  = m-1;
        int stepsRight = n-1;

        // Calculate the unique paths using combinatorics formula (totalSteps choose stepsDown)
        long long res = 1;
        for(int i=1; i<=stepsDown; ++i) {
            res *= (totalSteps - stepsDown + i);
            res /= i;
        }
        return res;
    }
};





// APPROACH 4

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2, R=m-1, i;
        double res=1;
        for(i=1;i<=R;i++){
            res=res*(N-R+i)/i;
        }
        return int(res);
    }
};

// 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2, R = m-1;
        double res = 1;
        for(int i=R; i>0; i--) {
            res *= N--;
            res /= i;
        }
        return round(res);
    }
};






// APPROACH 5 [ Memoization (Top-down) ] 
// builds upon the dynamic programming approach but uses memoization to avoid redundant calculations.

class Solution {
public:        
    int f(int i, int j, vector<vector<int>>& memo) {
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;        
        if(memo[i][j] != -1) return memo[i][j];
        
        memo[i][j] = f(i-1, j, memo) + f(i, j-1, memo);
        return memo[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return f(m - 1, n - 1, memo);
    }
};





// APPROACH 6  [ Space-Optimized DP ]
// OPTIMIZATION OF APPROACH 1

// WE can optimize the space complexity of the DP solution by using a single array of size n
// instead of a 2D matrix.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);         
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                dp[j] += dp[j-1]; 
            }
        }        
        return dp[n - 1]; 
    }
};






// APPROACH 7 
