// A1 -  Use flag vectors as bitmask, 4ms:

// The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.
// NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(ans, nQueens, flag_col, flag_45, flag_135, 0, n);
        return ans;
    }

    void solveNQueens(vector<vector<string>> &ans, vector<string> &nQueens, vector<int> &flag_col,vector<int> &flag_45, vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            ans.push_back(nQueens);
            return;
        }
        for(int col = 0; col != n; ++col)
            if(flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(ans, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};
