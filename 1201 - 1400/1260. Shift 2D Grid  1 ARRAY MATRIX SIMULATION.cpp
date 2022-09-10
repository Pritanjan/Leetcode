// leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        for(int i=0; i<m*n; i++){
            int row = i/n;
            int col = i%n;
            
            int Ncol = (k + col)%n;
            int Nrow = ((k + col)/n  + row)%m;
            ans[Nrow][Ncol] = grid[row][col];
            
        }

        return ans;
    }
};
