// A 1 - BFS

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






// A 2 - DFS - Recursive

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        
        // Define directions for up, down, left, and right
        int delRow[] = {-1,  0, 0,  1};
        int delCol[] = { 0, -1, 1, 0};

        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and 
                grid[nRow][nCol] == '1' and !vis[nRow][nCol]) {
                    dfs(nRow, nCol, vis, grid);
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
                    dfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};


// OR
// DFS - Recursive

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //Boundary condition 
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();

        // Count the number of islands  
        int cnt = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                // Only when the current grid is 1 will the calculation start
                if(grid[row][col] == '1') {
                    // If the current grid is 1, add 1 to the number of islands
                    cnt++;
                    // Then use dfs to set the four positions of the current grid, which are 1, to 0.
                    // Because they are connected together as an island,
                    dfs(row, col, grid);
                }
            }
        }
        // return the number of islands
        return cnt;
    }

private:
    // This method will set the current grid and its adjacent grids with 1 to 1
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Boundary condition, we cannot cross the boundary   
        if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] == '0') return ;
        
        // Set the current grid to 0
        grid[row][col] = '0';
        // traverse four directions up, down, left, and right
        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row, col+1, grid);
    }
};


// OR
// DFS - Iterative using Stack


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(grid[row][col] == '1') {
                    cnt++;
                    stack<pair<int, int>> stkp;
                    stkp.push({row, col});
                    grid[row][col] = '0';

                    while(!stkp.empty()) {
                        auto [x, y] = stkp.top();
                        stkp.pop();

                        for(auto &dir : dirs) {
                            int newX = x + dir[0];
                            int newY = y + dir[1];

                            if(newX >= 0 and newX < n and newY >=0 and newY < m and grid[newX][newY] == '1') {
                                stkp.push({newX, newY});
                                grid[newX][newY] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
























class Solution {
public:
    int cnt=0;

    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int m,n;

    void bfs(vector<vector<char>>& grid,int row,int col)
    {

        if(row<0||row>=m)  return;
        if(col<0||col>=n)  return;
        if(grid[row][col]!='1') return;
        grid[row][col]='2';
        for(int i=0;i<4;i++)
        {
            bfs(grid,row+dx[i],col+dy[i]);
        }

    }

    int numIslands(vector<vector<char>>& grid)
    {
        m=grid.size();
        n=grid[0].size();

        cout<<m<<" "<<n<<endl;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='1')
            {                cout<<"1";
                bfs(grid,i,j);

                cnt++;
            }
        }
        return cnt;
    }
};




