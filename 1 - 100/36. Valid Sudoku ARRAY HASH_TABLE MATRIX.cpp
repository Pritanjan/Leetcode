//https://leetcode.com/problems/valid-sudoku/

// Hash Set
//
//For each row, we create a HashSet to check for duplicates in each row.
//For each column, we also create a HashSet to check for duplicates in each column.
//For each square, we also create a HashSet to check for duplicates in each square, but we need to convert the position (r, c) in the board to square by:
//			Square row: sr = r / 3.
//			Square col: sc = c / 3.
//			Square position: sPos = sr * 3 + sc.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char>  sq[9];
        
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char val = board[r][c];
                
                if(val == '.')
                    continue;
                int shift = (r/3)*3 + (c/3);
                
                if(row[r].count(val) || col[c].count(val) || sq[shift].count(val))
                    return false;
                
                row[r].insert(val);
                col[c].insert(val);
                sq[shift].insert(val);
                
            }
        }
        return true;
    }
};




//Time: O(N^2), where N = 9.
//Space: O(N^2)
