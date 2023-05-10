// APPROACH 1


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n,0));
        int left = 0, right = n-1, top = 0, bottom = n-1; 
        
        int a = 1;
        
        while(left <= right || top <= bottom){
            for(int i=left; i<=right; i++){
                ans[top][i] = a++;
            }
            top ++;
            
            for(int i=top; i<=bottom; i++){
                ans[i][right] = a++;
            }
            right--;
            
            for(int i=right; i>=left; i--){
                ans[bottom][i] = a++;
            }
            bottom--;
            
            for(int i = bottom; i>=top; i--){
                ans[i][left] =a++;
            }
            left++;
        }
        return ans;
        
    }
};









// APPROACH 2 editoril


class Solution {
public:
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0, col = 0;

        while(cnt <= n * n) {
            res[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);

            // change direction if next cell is non zero
            if(res[r][c] != 0) d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
        }
        return res;
    }
};









// APPROACH 3


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for(int i=0; i<(n+1)/2; i++) {
            // direction 1 - traverse from left to right
            for(int j=i; j<n-i; j++) {
                result[i][j] = cnt++;
            }
            
            // direction 2 - traverse from top to bottom
            for(int j=i+1; j<n-i; j++) {
                result[j][n-i-1] = cnt++;
            }
            
            // direction 3 - traverse from right to left
            for(int j=n-i-2; j>=i; j--) {
                result[n-i-1][j] = cnt++;
            }
            
            // direction 4 - traverse from bottom to top
            for(int j=n-i-2; j>i; j--) {
                result[j][i] = cnt++;
            }
        }
        return result;
    }
};

