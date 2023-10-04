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






// A 2 - DFS









