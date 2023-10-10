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


// OR


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> que;
        int cntFresh = 0;      

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) que.push({i, j});
                else if(grid[i][j] == 1) cntFresh++;
            }
        }
        
        int time = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while(!que.empty() and cntFresh > 0) {
            int size = que.size();
            for(int i=0; i<size; i++) {
                int row = que.front().first;
                int col = que.front().second;
                que.pop();

                for(int j=0; j<4; j++) {
                    int nRow = row + dx[j];
                    int nCol = col + dy[j];
                    if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m  and grid[nRow][nCol] == 1) {
                        que.push({nRow, nCol});
                        grid[nRow][nCol] = 2;
                        cntFresh--;
                    }
                }
            }          
            time++;
        }
        if(cntFresh > 0) return -1;
        return time;
    }
};


// OR


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> que;
        int cntFresh = 0;      

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) que.push({i, j});
                else if(grid[i][j] == 1) cntFresh++;
            }
        }
        
        int time = 0;
        if(cntFresh == 0) return 0;

        while(!que.empty()) {
            int size = que.size();
            bool change = false;

            for(int i=0; i<size; i++) {
                int row = que.front().first;
                int col = que.front().second;
                que.pop();

                for(auto &d : dir) {
                    int nRow = row + d.first;
                    int nCol = col + d.second;
                    if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m  and grid[nRow][nCol] == 1) {
                        que.push({nRow, nCol});
                        grid[nRow][nCol] = 2;
                        cntFresh--;
                        change = true;
                    }
                }
            }
            if(change) time++;
        }
        if(cntFresh > 0) return -1;
        return time;
    }
};






// A 2

class Solution {
public:
    vector<vector<int>> res;
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }

        res = grid;
        for(int i=0; i<res.size(); i++) {
            for(int j=0; j<res[0].size(); j++) {
                if(res[i][j] == 2) {
                    dfs(i, j, 2); // Start infection
                }
            }
        }

        int maxLevel = 0;
        for(int i=0; i<res.size(); i++) {
            for(int j=0; j<res[0].size(); j++) {
                if(res[i][j] == 1) {
                    return -1; // If there are fresh oranges not infected, return -1
                } 
                else {
                    maxLevel = max(maxLevel, res[i][j]);
                }
            }
        }
        return maxLevel == 0 ? 0 : maxLevel - 2;
    }

    void dfs(int i, int j, int level) {
        if(i < 0 || i >= res.size() || j < 0 || j >= res[0].size()) return;
        if (res[i][j] != 1 && res[i][j] < level) return ;

        res[i][j] = level;
        level++;
        
        dfs(i-1, j, level);
        dfs(i+1, j, level);
        dfs(i, j-1, level);
        dfs(i, j+1, level);
    }
};






