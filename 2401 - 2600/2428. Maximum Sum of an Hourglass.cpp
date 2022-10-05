// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

class Solution {
public:
    int maxSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m < 3 or n < 3)
            return 0;
        
        int ma = INT_MIN;
        for(int i=0; i<m-2; i++){
            for(int j=0; j<n-2; j++){
                int sum = (matrix[i][j] + matrix[i][j+1] + matrix[i][j+2] + matrix[i+1][j+1] + matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2]);
                
                ma = max(ma, sum);
            }
        }
        return ma;
    }
};


