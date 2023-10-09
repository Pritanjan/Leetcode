// A 1 BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> que;
        int vis[n][m];  

        int cntFresh = 0;      
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    que.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1) cntFresh++;
            }
        }
        
        int time = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int cnt =0;
        while(!que.empty()) {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int tme = que.front().second;
            time = max(tme, time);
            que.pop();

            for(int i=0; i<4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and vis[nRow][nCol] == 0 and grid[nRow][nCol] == 1) {
                    que.push({{nRow, nCol}, time + 1});
                    vis[nRow][nCol] = 2;
                    cnt++;
                }
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(vis[i][j] != 2 and grid[i][j] == 1) {
        //             return -1;
        //         }
        //     }
        // }
        if(cnt != cntFresh) return -1;
        return time;
    }
};







// A 2
