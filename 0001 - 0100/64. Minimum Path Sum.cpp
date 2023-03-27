// APPROACH 1

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width = grid[0].size(), high = grid.size();
        if (high == 0 || width == 0) return 0;
        // initialization
        for (int i = 1; i < high; i++) grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < width; i++) grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < high; i++)
            for (int j = 1; j < width; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        return grid[high - 1][width - 1];
    }
};




// APPROACH 2


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[row - 1].size();

        vector<vector<int>> dp(row, vector<int>(col));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};






