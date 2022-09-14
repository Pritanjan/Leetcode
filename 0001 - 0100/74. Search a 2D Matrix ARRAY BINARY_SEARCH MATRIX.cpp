// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row    = matrix.size();
        int column = matrix[0].size();
        int left   = 0;
        int right  = row * column -1;
        
        while(left <= right){
            int mid = (left + right)/2;
            if(target == matrix [mid / column] [mid % column] )
                return true;
            else if(target < matrix [mid / column] [mid % column] )
                right  = mid - 1;
            if(target > matrix [mid / column] [mid % column] )
                left = mid + 1;
            
        }
        return false;
    }
};

// matrix[index/column][index%column]
// O(log mn)



// 1 So a cell value can be calculated by:
//   cell value = Total col * row + col.
//
// 2 To get the row we’ll divide the cell value by the total column:
//   row = cell value / Total col.
//
// 3 For columns, we have to take the remainder values when an int is divided by the column value.
//   col = cell value % Total col.
//
// 4 Now simply run Binary search algorithm & search the target.
//   Time complexity: O(logn).

//  Now the number of columns = matrix[0].length
//  So to fetch element at any index, we can do it by, matrix[index/column][index%column].




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        bool isFound = false;
            
      // Staircase search technique  
       while(j>=0 && i < matrix.size()) {
        
           if (matrix[i][j]==target) {
               isFound = true;
               break;
           } else if (matrix[i][j] > target) {
               j--;
           } else {
               i++;
           }
       }     
            
       return isFound; 
    }
};


