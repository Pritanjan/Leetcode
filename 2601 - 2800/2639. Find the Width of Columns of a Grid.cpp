class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n, 0);

        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                int W = (grid[i][j] >= 0) ? 1 : 2; 
                int num = abs(grid[i][j]);
                while(num > 9) {
                    W++;
                    num /= 10;
                }
                ans[j] = max(ans[j], W);
            }
        }

        return ans;
    }
};


