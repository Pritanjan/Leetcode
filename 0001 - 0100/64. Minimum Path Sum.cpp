// APPROACH 1

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width = grid[0].size(), high = grid.size();
        if (high == 0 || width == 0) return 0;

        // initialization
        for(int i=1; i<high; i++)    grid[i][0] += grid[i - 1][0];
        for(int i=1; i<width; i++)   grid[0][i] += grid[0][i - 1];

        for(int i=1; i<high; i++) {
            for (int j = 1; j < width; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }            
        return grid[high - 1][width - 1];
    }
};





// APPROACH 2

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int row = grid.size();
        int col = grid[row - 1].size();

        vector<vector<int>> dp(row, vector<int>(col));

        dp[0][0] = grid[0][0];

        for(int i=1; i<row; i++)  dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int i=1; i<col; i++)  dp[0][i] = dp[0][i - 1] + grid[0][i];

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};









// APPROACH 3

class Solution {
public:
    int help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[i][j];   // return grid[0][0];
        if(i < 0  || j < 0)  return INT_MAX; 
        if(dp[i][j] != -1) return dp[i][j];   
        
        long long up   = (long long)grid[i][j] + (long long) help(i-1, j, grid, dp);
        long long left = (long long)grid[i][j] + (long long) help(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);

        // above 3 line is same as this 
        // return dp[i][j] = grid[i][j] + min(help(i-1, j, grid, dp), help(i, j-1, grid, dp));
        
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return help(m-1,n-1,grid,dp);
    }
};





// APPROACH 4

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
       
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0)  dp[i][j]=grid[i][j];
                else { 
                    int up = grid[i][j];
                    if (i > 0) up += dp[i-1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0)  left += dp[i][j-1];
                    else  left += 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1] ;
    }
};







// APPROACH 6

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return help(m-1,n-1,grid,dp);

        int dp[m][n];
        // dp[0][0]=grid[0][0];
        
        vector<int> prev(n,0);
        for(int i=0; i<m; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0)  curr[0] = grid[i][j];
                else {
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;
                    int left = grid[i][j];

                    if(j > 0) left += curr[j-1]; 
                    else left += 1e9;

                    curr[j] = min(left, up);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};





// APPROACH 7

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // to store min num
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));  

        for(int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                int case1 = 1e9;
                int case2 = 1e9;

                min_suresm[i][j] = grid[i][j];
                
                if (i == 0 && j == 0) continue;
                if (i > 0) case1 = res[i - 1][j];
                if (j > 0) case2 = res[i][j - 1];
                
                res[i][j] += min(case1, case2);
            }
        }
        return res.back().back();
    }
};










