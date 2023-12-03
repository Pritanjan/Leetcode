// A 1

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size() - 1; i++) {
            int curX = points[i][0];
            int curY = points[i][1];
            int tgtX = points[i+1][0];
            int tgtY = points[i+1][1];
            ans += max(abs(tgtX - curX), abs(tgtY - curY));
        }
        return ans;
    }
};






// A 2

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTime = 0;
        for (int i = 1; i < points.size(); ++i) {
            minTime += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }

        return minTime;
    }
};

