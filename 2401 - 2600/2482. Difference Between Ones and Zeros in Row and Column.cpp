// A 1

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRows(m, 0);
        vector<int> onesCols(n, 0);
        vector<int> zeroRows(m, 0);
        vector<int> zeroCols(n, 0);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                onesRows[i] += grid[i][j];
                onesCols[j] += grid[i][j];
            }
        }

        for(int i=0; i<m; i++) zeroRows[i] = n - onesRows[i];
        for(int i=0; i<n; i++) zeroCols[i] = m - onesCols[i];

        vector<vector<int>> diff(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                diff[i][j] = onesRows[i] + onesCols[j] - zeroRows[i] - zeroCols[j];
            }
        }
        return diff;
    }
};






// A 2
