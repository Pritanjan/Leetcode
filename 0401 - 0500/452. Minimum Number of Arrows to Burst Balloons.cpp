class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 1;
        int j = 0, n = points.size();

        for(int i=n-2; i>=0; i--){
            if(points[i][1] < points[n-j-1][0]){
                cnt++;
                j = n-i-1;
            }
        }
        return cnt;
    }
};

// 1         6
//    2              8
//              7           12
//                      10         16
        
