//https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int n = matrix.size();          // no. of row
        int m = matrix[0].size();       // no. of col
        int x,y,cnt;
        
        // moving along the columns
        for(int i=0; i<m; i++){
            vector<int> val;
            x = i;
            y = 0;
            while(x < m and y < n){
                val.push_back(matrix[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = i;
            y = 0;
            cnt = 0;
            while(x < m and y < n){
                matrix[y][x] = val[cnt];
                x++;
                y++;
                cnt++;
            }
        }
        
        // moving along the rows
        for(int i=1; i<n; i++){
            vector<int> val;
            x = 0;
            y = i;
            while(x < m and y < n){
                val.push_back(matrix[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = 0;
            y = i;
            cnt = 0;
            while(x < m and y < n){
                matrix[y][x] = val[cnt];
                x++;
                y++;
                cnt++;
            }
        }
        return matrix;
    }
};

// https://www.youtube.com/watch?v=JV2x41rSVAI




class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int k=0; k<m; k++){
            for(int i=0; i<m-1; i++){
                for(int j=0; j<n-1; j++){
                    if(matrix[i][j] > matrix[i+1][j+1])
                        swap(matrix[i][j], matrix[i+1][j+1]);
                }
            }
        }
        return matrix;
    }
};




// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44
