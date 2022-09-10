//https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    
    vector<vector<int>> sum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        sum = vector<vector<int>> (m+1, vector<int>(n+1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {        
        return sum[r2+1][c2+1] - sum[r2+1][c1] - sum[r1][c2+1] + sum[r1][c1];
    }
};
