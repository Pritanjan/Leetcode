// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0060%20230323%20Unique%20Paths%20in%20a%20Grid.cpp

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


class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(i==0 || j==0)
                   dp[i][j]=1;
               else
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
           }
        }
        return dp[m-1][n-1];
    }
};


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


