// APPROACH 1


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = coordinates[1][1] - coordinates[0][1];
        int x = coordinates[1][0] - coordinates[0][0];
        
        for(int i=2; i<coordinates.size(); i++){
            if(  x * (coordinates[i][1] - coordinates[0][1]) !=  y * (coordinates[i][0] - coordinates[0][0]))
                return false;
        }
        return true;
    }
};





// APPROACH 1


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         int n = coordinates.size();
    
        if(n <= 2) {
            return true; // If there are 0 or 1 points, they always form a straight line
        }
        
        // Calculate the slope between the first two points
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        // Check if all subsequent points lie on the same line
        for(int i=2; i<n; i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            
            // If the current point does not lie on the line, return false
            if(dy * (xi-x0) != dx * (yi-y0)) {
                return false;
            }
        }        
        return true;
    }
};






