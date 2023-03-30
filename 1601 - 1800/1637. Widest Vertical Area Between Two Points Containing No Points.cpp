// APPROACH 1 [BRUTE FORCE ]

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        int max_width = 0;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(points[i][0] != points[j][0]) {
                    int width = abs(points[i][0] - points[j][0]);
                    bool contains_points = false;
                    for(int k=0; k<n; ++k) {
                        if(k != i && k != j && points[k][0] > min(points[i][0], points[j][0]) && points[k][0] < max(points[i][0], points[j][0])) {
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






// APPROACH 4

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); // sort the points by x-coordinate
        int max_width = 0;
        
        for (int i=1; i<points.size(); ++i) {
            int width = points[i][0] - points[i-1][0]; // calculate the width between adjacent points
            max_width = max(max_width, width);         // update max_width if necessary
        }
        return max_width;
    }
};

// T.C. --> O(N log N) , for  sort() function
// S.C. --> O(N),        for store the sorted points.




// APPROACH 4 [BY USING LAMBDA FUNCTION ]

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int max_width = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            max_width = max(max_width, points[i+1][0] - points[i][0]);
        }
        return max_width;
    }
};


// T.C. --> O(N log N) 
// S.C. --> O(N)



