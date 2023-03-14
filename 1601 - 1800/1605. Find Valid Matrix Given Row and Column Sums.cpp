class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            int val = min(rowSum[i], colSum[j]);
            matrix[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            
            if (rowSum[i] == 0) i++;
            if (colSum[j] == 0) j++;
        }
        return matrix;
    }
};

// We start by initializing a matrix of size m x n with all zeroes. 
// Then, we iterate through the rows and columns of the matrix using two indices i and j, respectively
// At each iteration, we compute the minimum value between rowSum[i] and colSum[j]
// and assign it to matrix[i][j]. We subtract this value from both rowSum[i] and colSum[j].

// If rowSum[i] becomes zero, it means we have filled up all the cells in row i.
// Therefore, we move to the next row by incrementing i. 
// Similarly, if colSum[j] becomes zero, we move to the next column by incrementing j.

// We continue this process until we have filled up all the cells in the matrix. 
// Finally, we return the matrix.


// T.C. -->  O(m*n), where m and n are the sizes of the rowSum and colSum vectors, respectively.
// This is because we iterate through each row and column of the matrix exactly once,
// and the time taken to perform each iteration is constant.

// S.C. --> O(m*n), as we create a matrix of size m x n to store the result.
// We do not use any other data structures or variables that would significantly 
// increase the memory usage.



