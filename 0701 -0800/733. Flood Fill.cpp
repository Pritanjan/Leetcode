// A 1 - BFS Using Queue

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& image, int color) {
        int n = image.size();
        int m = image[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1 , -1};
        
        int originalColor = image[row][col];
        if(originalColor == color) return ;

        queue<pair<int, int>> quep;
        quep.push({row, col});
        image[row][col] = color;

        while (!quep.empty()) {
            int row = quep.front().first;
            int col = quep.front().second;
            quep.pop();

            for(int i=0; i<4; i++) {
                int nRow = dx[i] + row;
                int nCol = dy[i] + col;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    image[nRow][nCol] == originalColor) {
                        image[nRow][nCol] = color;
                    quep.push({nRow, nCol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if (image.empty() || image[sr][sc] == color) {
            return image;
        }
        bfs(sr, sc, image, color);
        return image;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        
        if(oldColor != color) {
            queue<pair<int, int>> que;
            que.push({sr, sc});
            
            while(!que.empty()) {
                auto [r, c] = que.front();
                que.pop();

                if(r < 0 or r >= n or c < 0 or c >= m or image[r][c] != oldColor) continue ;

                image[r][c] = color;
                que.push({r+1, c});
                que.push({r-1, c});
                que.push({r, c+1});
                que.push({r, c-1});
            }
        }
        return image;
    }
};






// A 2 - DFS - Recursive

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldColor) {
            return;
        }
        image[r][c] = newColor;
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
};






// A 3 -  DFS Iterative using a Stack

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            stack<pair<int, int>> stk;
            stk.push({sr, sc});
            
            while (!stk.empty()) {
                int r, c;
                tie(r, c) = stk.top();
                stk.pop();
                
                if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldColor) {
                    continue;
                }
                
                image[r][c] = newColor;
                
                stk.push({r + 1, c});
                stk.push({r - 1, c});
                stk.push({r, c + 1});
                stk.push({r, c - 1});
            }
        }
        return image;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            stack<pair<int, int>> stk;
            stk.push({sr, sc});
            
            while (!stk.empty()) {
                int r, c;
                tie(r, c) = stk.top();
                stk.pop();
                
                if (image[r][c] != oldColor) {
                    continue;
                }
                
                image[r][c] = newColor;
                
                if (r > 0) stk.push({r - 1, c});
                if (r < image.size() - 1) stk.push({r + 1, c});
                if (c > 0) stk.push({r, c - 1});
                if (c < image[0].size() - 1) stk.push({r, c + 1});
            }
        }
        return image;
    }
};






// A 3 - Using a Visited Set (DFS)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            unordered_set<string> visited;
            dfs(image, sr, sc, oldColor, newColor, visited);
        }
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor, unordered_set<string>& visited) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldColor || visited.count(to_string(r) + "-" + to_string(c)) > 0) {
            return;
        }
        
        visited.insert(to_string(r) + "-" + to_string(c));
        image[r][c] = newColor;
        
        dfs(image, r + 1, c, oldColor, newColor, visited);
        dfs(image, r - 1, c, oldColor, newColor, visited);
        dfs(image, r, c + 1, oldColor, newColor, visited);
        dfs(image, r, c - 1, oldColor, newColor, visited);
    }
};






// A 4 
// Union-Find (Connected Components):

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        
        if (oldColor != newColor) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            // Initialize Union-Find data structure
            vector<int> parent(m * n, -1); // Parent array to track connected components
            
            // Convert 2D coordinates to 1D index
            auto index = [&](int i, int j) {
                return i * n + j;
            };
            
            // Perform depth-first search to identify connected components
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!visited[i][j] && image[i][j] == oldColor) {
                        dfs(image, i, j, oldColor, newColor, visited, parent, index);
                    }
                }
            }
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor,
             vector<vector<bool>>& visited, vector<int>& parent, function<int(int, int)> index) {
        int m = image.size();
        int n = image[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || image[r][c] != oldColor) {
            return;
        }

        visited[r][c] = true;
        image[r][c] = newColor;

        // Check the neighboring cells
        int neighbors[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& neighbor : neighbors) {
            int newRow = r + neighbor[0];
            int newCol = c + neighbor[1];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] &&
                image[newRow][newCol] == oldColor) {
                // Union the current cell with its neighbor
                int currentIdx = index(r, c);
                int neighborIdx = index(newRow, newCol);
                parent[currentIdx] = neighborIdx;
                
                dfs(image, newRow, newCol, oldColor, newColor, visited, parent, index);
            }
        }
    }
};



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            dfs(image, sr, sc, oldColor, newColor, visited);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor, vector<vector<bool>>& visited) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || visited[r][c] || image[r][c] != oldColor) {
            return;
        }

        visited[r][c] = true;
        image[r][c] = newColor;

        dfs(image, r + 1, c, oldColor, newColor, visited);
        dfs(image, r - 1, c, oldColor, newColor, visited);
        dfs(image, r, c + 1, oldColor, newColor, visited);
        dfs(image, r, c - 1, oldColor, newColor, visited);
    }
};
