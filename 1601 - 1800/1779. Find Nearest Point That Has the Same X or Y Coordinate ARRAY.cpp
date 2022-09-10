// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& pt) {
        int ans =  -1;
        int q   = INT_MAX;
        
        for(int i=0; i<pt.size(); i++){
            if(pt[i][0] == x || pt[i][1] == y ){
                int d = abs(x - pt[i][0]) + abs(y - pt[i][1]);
                
                if(d < q){
                    ans = i;
                    q = d;
                }       
            }
        }
        return ans;
    }
};


