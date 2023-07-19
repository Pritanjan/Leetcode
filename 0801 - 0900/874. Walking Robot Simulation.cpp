class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        unordered_set<long> ust;
        for(auto &v:obstacles) us.insert((v[0] + 30000) * 60001l + v[1] + 30000);
        
        int x = 0, y = 0;
        int d = 0;
        int ans = 0;
        for(int a : commands) { 
            if(a==-2) d = (d+3)%4;
            else if(a==-1) d = (d+1)%4;
            else {
                for(int i=1; i<=a; i++) {
                    if(ust.count((x + dirs[d][0] + 30000) * 60001l + y + dirs[d][1] + 30000)) break;
                    x += dirs[d][0];
                    y += dirs[d][1];
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};







class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (auto &obstacle : obstacles) mp.emplace(obstacle[0] * 60001 + obstacle[1]);
        
        int res = 0;
        for(int c : commands) {
            if(c < 0) {
                d += c == -1 ? 1 : -1;
                d %= 4;
                if(d < 0) d += 4;
            } 
            else {
                for(int i=0; i<c; i++) {
                    if(mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) break;
                    px += dirs[d][0];
                    py += dirs[d][1];
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};

