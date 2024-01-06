// A 1 

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int k = 0;
                for(; k<n; k++) {
                    if(grid[i][k] != grid[k][j]) break;
                }
                if(k == n) cnt++;  // row[i] = col[j]
            }
        }
        return cnt;
    }
};






// A 2 

