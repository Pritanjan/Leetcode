class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxDist = -1;
        
        vector<pair<int, int>> lands, waters;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) lands.emplace_back(i, j);
                else waters.emplace_back(i, j);
            }
        }
        
        if (lands.empty() || waters.empty()) {
            return -1;
        }

        for(auto& water : waters) {
            int minDist = INT_MAX;
            for(auto& land : lands) {
                int dist = abs(water.first - land.first) + abs(water.second - land.second);
                minDist = min(minDist, dist);
            }
            maxDist = max(maxDist, minDist);

        }        
        return maxDist;
    }
};




