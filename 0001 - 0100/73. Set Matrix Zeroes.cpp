// A 1

// Using Extra Space (Hash Sets):
// This approach uses two hash sets to keep track of which rows and columns need to be zeroed out.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<int> v1,v2;
        set<int> r;
        set<int> c;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }  
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(r.count(i) or c.count(j))
                    matrix[i][j] = 0;
            }
        }
        // return matrix;
    }
};


// OR


// Using Extra Space (Arrays):
// This approach uses two arrays to keep track of which rows and columns need to be zeroed out.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size());
        vector<bool> column(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row[i] || column[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// OR


// Using Extra Space (Arrays):
// This approach uses two arrays to keep track of which rows and columns need to be zeroed out.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// OR



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mat[m][n];			
        memset(mat, 0, sizeof(mat));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if(matrix[i][j] == 0) mat[i][j] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1) {
                    for (int k = 0; k < m; k++) matrix[k][j] = 0;
                    for (int k = 0; k < n; k++) matrix[i][k] = 0;
                }
            }
        }
    }
};






// A 2 - In-Place Approach:
// It modifies the matrix in place without using extra space. 
// It uses the first row and first column to keep track of which rows 
// and columns need to be zeroed out.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // check if first row has zero
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // check if first column has zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // use first row and column as markers for zeros in other rows and columns
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set zeros for rows and columns marked in first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set zeros for first row and column if necessary
        if (firstRowZero) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};






// A 3
