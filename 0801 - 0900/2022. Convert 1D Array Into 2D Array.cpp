// A 1

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {}; 
        }

        vector<vector<int>> v(m, vector<int>(n));
        
        int idx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                v[i][j] = original[idx];
                idx++;
            }
        }
        return v;
    }
};
