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





















class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //Boundary condition judgment
        if(grid.empty() || grid[0].empty()) return 0;
        
        // Count the number of islands
        int count = 0;
        
        //Two for loops to traverse each grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                //Only when the current grid is 1 will the calculation start
                if (grid[i][j] == '1') {
                    //If the current grid is 1, add 1 to the number of islands
                    count++;
                    //Then use dfs to set the four positions of the current grid, which are 1, to 0.
                    //Because they are connected together as an island,
                    dfs(grid, i, j);
                }
            }
        }
        // Finally return the number of islands
        return count;
    }

    // This method will set the current grid and its adjacent grids with 1 to 1
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary condition judgment, cannot cross the boundary        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        //Set the current grid to 0, and then continue traversing from its four directions up, down, left, and right
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
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




