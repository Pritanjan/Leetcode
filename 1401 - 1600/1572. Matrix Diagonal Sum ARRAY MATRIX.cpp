//https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || i+j == n-1 )
                    sum += matrix[i][j];
            }
        }
        return sum;
    }
};
