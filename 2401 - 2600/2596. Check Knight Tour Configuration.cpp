class Solution {
public:
    bool valid(vector<vector<int>>& grid, int row, int col, int n, int cnt) {
        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != cnt)
            return false;
        
        if(cnt == n*n - 1) return true;
        
        int x[] = {2, 2, -2, -2, 1, -1, 1, -1};
        int y[] = {1, -1, 1, -1, 2, 2, -2, -2};
        
        for(int i = 0; i < 8; i++) {
            int X = row + x[i];
            int Y = col + y[i];
            if(valid(grid, X, Y, n, cnt + 1)) return true;
        }
        
        return false;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return valid(grid, 0, 0, n, 0);
    }
};
