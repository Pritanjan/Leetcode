// A 1

class Solution {
  private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        queue<pair<int, int>> que;
        que.push({row, col});
        
        // Define directions for up, down, left, and right
        int delRow[] = {-1,  0, 0,  1};
        int delCol[] = { 0, -1, 1, 0};

        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            // Traverse in the four cardinal directions and mark if it's land
            // traveres in the neighours & mark them if it land
            for(int i=0; i<4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                // to check whether if they r going out of the boundry or not  
                if(nRow >= 0 and nRow < n and nCol >=0 and nCol < m
                   and grid[nRow][nCol] == '1' and !vis[nRow][nCol]) {
                        vis[nRow][nCol] = 1;
                        que.push({nRow, nCol});
                        
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!vis[row][col] and grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};






// A 2



