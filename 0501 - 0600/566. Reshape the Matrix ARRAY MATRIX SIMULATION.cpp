//https://leetcode.com/problems/reshape-the-matrix/

//Solution 1 (Row-First Approach)
//Iterate each row column-by-column, wrap around when you reach the end
//on one row and move to the next row. Here, we are copying all elements
//of one row and then moving on to the next row.

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m*n;
        
        if(r*c != size)		// return if total elements don't match
            return matrix;
            
        vector<vector<int>> ans(r, vector<int> (c,0));
        for(int i=0; i<size; i++){
            ans[i/c][i%c] = matrix[i/n][i%n];
        }
        return ans;
    }
};

//Time  Complexity : O(r*c)
//Space Complexity : O(1), ignoring output space complexity
