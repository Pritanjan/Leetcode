// A 1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();			// no. of rows
        int n = matrix[0].size();	        // no. of cols
        // int n = m ? matrix[0].size() : 0;    // both line are same
           
	// initialize i and j so that we can start iterating the matrix from  last row's first element
	int i = 0;
        int j = n - 1;
        
        // until we come to first row's last element
        while( i < m && j >=0){
            // if element found to be equal to target, return true
            if(target == matrix[i][j]) return true;
            // if element is lesser than  the target, move up because all  the smallest elements are above it,  as Integers in each row are sorted in ascending from left to right. Integers in each column are sorted in ascending from top to bottom.
            else if (target > matrix[i][j]) i++;
            // otherwise if element is lesser than the target move right, as all greater elements lives in right.
            else j--;        
        }
        // if element is not found, return false
        return false;
    }
};

// Start search the matrix from top right corner, initialize the current position to top right corner, 
// if the target is greater than the value in current position, 
// then the target can not be in entire row of current position because the row is sorted, 
// if the target is less than the value in current position, then target can not be in the entire 
// column because the column is sorted too.
// We can rule out one row or one column each time, 
// so the time complexity is O(m + n).




