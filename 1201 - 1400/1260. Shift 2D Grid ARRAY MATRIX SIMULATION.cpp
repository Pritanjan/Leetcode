// leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int Ncol = (j+k)%n;
                int a = (j+k)/n;		//  how many row numbers can be increased if we shift by k.
                int Nrow = (i+a)%m;
                
                ans[Nrow][Ncol] = grid[i][j];
            }
        }
        
        return ans;
    }
};
