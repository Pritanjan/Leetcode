//https://leetcode.com/problems/reshape-the-matrix/

//Solution - II (Column-First Appraoch)
//Iterate each column row-by-row, wrap around when you reach the end on
//one column and then move to the next column. Here, we are copying all
//elements of one column and then moving on to the next column.

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m*n;
        
        if(r*c != size)
            return matrix;
        
        vector<vector<int>> ans(r, vector<int> (c));
        for(int col=0; col<m; col++){
            for(int row=0; row<n; row++){
            	int k = col*n + row;
            	ans[k/c][k%c] = matrix[col][row];
            }
        }
        return ans;
    }
}; 

//Time  Complexity : O(r*c)
//Space Complexity : O(1), ignoring output space complexity
