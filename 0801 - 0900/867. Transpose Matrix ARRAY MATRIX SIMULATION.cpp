//https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat1(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                mat1[i][j] = matrix[j][i];
            }
        }
        return mat1;
    }
};
