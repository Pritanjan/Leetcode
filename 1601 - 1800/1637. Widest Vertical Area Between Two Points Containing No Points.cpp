// APPROACH 1 [BRUTE FORCE ]

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        int max_width = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] != points[j][0]) {
                    int width = abs(points[i][0] - points[j][0]);
                    bool contains_points = false;
                    for (int k = 0; k < n; ++k) {
                        if (k != i && k != j && points[k][0] > min(points[i][0], points[j][0]) &&
                            points[k][0] < max(points[i][0], points[j][0])) {
                            contains_points = true;
                            break;
                        }
                    }
                    if (!contains_points) {
                        max_width = max(max_width, width);
                    }
                }
            }
        }
        return max_width;
    }
};





// APPROACH 2

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xpos;
        for (int i = 0; i < points.size(); i++) {
            xpos.push_back(points[i][0]);
        }
        sort(xpos.begin(), xpos.end());
        // int min_len = 1000000000;
        // for (int i = 0; i < xpos.size()-1; i++) {
        //     min_len = xpos[i+1] - xpos[i] < min_len ? xpos[i+1] - xpos[i]: min_len;
        // }
        // return min_len;

        int max_len = 0;
        for (int i = 0; i < xpos.size()-1; i++) {
            max_len = xpos[i+1] - xpos[i] > max_len ? xpos[i+1] - xpos[i]: max_len;
        }
        return max_len;
    }
};






// APPROACH 3


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x;
        for(auto& point : points) x.insert(point[0]);

        int max_width = 0;
        for (auto it = x.begin(); next(it) != x.end(); ++it) {
            max_width = max(max_width, *next(it) - *it);
        }
        return max_width;
    }
};


