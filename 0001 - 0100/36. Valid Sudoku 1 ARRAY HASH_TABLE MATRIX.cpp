// https://leetcode.com/problems/valid-sudoku/

// company Tag :- fb microsoft amazon uber

// Bitmasking (Beat 100%)
//
//Since we only need to store 2 states (exist, not exist) and store up to 9 positions.
//So to save space, we can store in the bitmask, i th bit represent the existence of the number i.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        vector<int> rows(N), cols(N), squares(N);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == '.') continue;
                int val = board[r][c] - '0';
                int sPos = (r / 3) * 3 + (c / 3);
                if (getBit(rows[r], val) || getBit(cols[c], val) || getBit(squares[sPos], val))
                    return false;
                rows[r] |= 1 << val;
                cols[c] |= 1 << val;
                squares[sPos] |= 1 << val;
            }
        }
        return true;
    }
    int getBit(int x, int k) {
        return (x >> k) & 1;
    }
};

//Time: O(N^2), where N = 9.
//Space: O(N)
