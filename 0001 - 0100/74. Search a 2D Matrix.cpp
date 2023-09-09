// A 1 [ Treat the 2D matrix as a flattened 1D array and perform binary search ]

// 1  So a cell value can be calculated by:
//    cell value = Total col * row + col.
// 2  To get the row we’ll divide the cell value by the total column:
//    row = cell value / Total col.
// 3  For columns, we have to take the remainder values when an int is divided by the column value.
//    col = cell value % Total col.
// 4  Now simply run Binary search algorithm & search the target.
//    Time complexity: O(logn).
//    Now the number of columns = matrix[0].length
//    So to fetch element at any index, we can do it by, matrix[index/column][index%column].

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row    = matrix.size();
        int column = matrix[0].size();
        int left   = 0;
        int right  = row * column -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(target == matrix [mid / column] [mid % column] )  return true;
            else if(target < matrix [mid / column] [mid % column] ) right  = mid - 1;
            if(target > matrix [mid / column] [mid % column] ) left = mid + 1;
        }
        return false;
    }
};

// matrix[index/column][index%column]
// O(log m n)






// A 2 Using Bool

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int i = 0, j = matrix[0].size()-1;
       bool isFound = false;
       // Staircase search technique  
       while(j>=0 && i < matrix.size()) {
           if(matrix[i][j]==target) {
               isFound = true;
               break;
           } 
           else if (matrix[i][j] > target) j--;
           else i++;
       }                 
       return isFound; 
    }
};






// A 3 [ Optimal Binary Search on Matrix Diagonals ]  without Using Bool 

// It takes advantage of the fact that the matrix is sorted both row-wise and column-wise.
// Start at the top-right corner of the matrix and move diagonally while 
// comparing the current element with the target. 
// Adjust the row or column accordingly to narrow down the search space.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int i = 0;
        int j = n - 1;
        while(i < m && j >=0) {
            if (target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) i++;
            else j--;        
        }
        return false;
    }
};






// A 4 [ Use binary search twice - first on rows, then on columns ]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1;
        
        // Binary search to find the potential row
        while(top <= bottom) {
            int row_mid = top + (bottom - top) / 2;
            if(matrix[row_mid][0] <= target && matrix[row_mid][n - 1] >= target) {
                int L = 0;
                int R = n - 1;
                
                // Binary search within the potential row
                while(L <= R) {
                    int col_mid = L + (R - L) / 2;
                    if(matrix[row_mid][col_mid] == target) return true;
                    else if(matrix[row_mid][col_mid] < target) L = col_mid + 1;
                    else R = col_mid - 1;
                }                
                return false;
            }
            else if(matrix[row_mid][0] > target) bottom = row_mid - 1;
            else top = row_mid + 1;
        }        
        return false;
    }
};






// A 5 [ Optimal Binary Search on Rows ]

// Here, we perform a binary search on each row of the matrix to find the potential row where
// the target might exist. 
// Then, perform another binary search within that row to find the target.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; ++i) {
            int L = 0;
            int R = n-1;
            while(L <= R) {
                int mid = L + (R - L) / 2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) L = mid + 1;
                else R = mid - 1;
            }
        }        
        return false;
    }
};






// A 6

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0;
        int bottom = m - 1;        
        // First binary search to find the row
        while(top <= bottom) { 
            int mid = top + (bottom - top) / 2;
            if(matrix[mid][0] <= target) top = mid + 1;
            else bottom = mid - 1;
        }
        
        if(bottom < 0) return false;        

        // Second binary search within the found row
        int row = bottom;
        int L = 0;
        int R = n - 1;        
        while(L <= R) {
            int mid = L + (R - L) / 2;
            int midVal = matrix[row][mid];
            
            if(midVal == target) return true;
            else if(midVal < target) L = mid + 1;
            else R = mid - 1;
        }        
        return false;
    }
};






// A 7

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j] == target) return true;
            }
        }        
        return false;
    }
};






// A 8 - Recursion
// Divide the matrix into submatrices and recursively searching for the target
// in the appropriate submatrix. 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        return searchSubmatrix(matrix, target, 0, 0, m-1, n-1);
    }

    bool searchSubmatrix(vector<vector<int>>& matrix, int target, int top, int L, int bottom, int R) {
        if(top > bottom || L > R) return false;
        int midRow = top + (bottom - top) / 2;
        int midCol = L + (R - L) / 2;
        int midVal = matrix[midRow][midCol];

        if(midVal == target) return true;
        // Search in the right and bottom submatrices
        else if(midVal < target) {
            return searchSubmatrix(matrix, target, midRow + 1, L, bottom, R) ||
                   searchSubmatrix(matrix, target, top, midCol + 1, midRow, R);
        } 
        // Search in the left and top submatrices
        else {
            return searchSubmatrix(matrix, target, top, L, midRow - 1, R) ||
                   searchSubmatrix(matrix, target, midRow, L, bottom, midCol - 1);
        }
    }
};






// A 9


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;        
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;
        
        while(row < m && col >= 0) {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++; // Move down
            else col--; // Move left
        }        
        return false;
    }
};



