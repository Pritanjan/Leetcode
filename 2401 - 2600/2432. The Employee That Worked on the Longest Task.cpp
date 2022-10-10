// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ma = -1, pos = -1, last = 0;
        
        for(auto i : logs){
            int cur = i[1] - last;
            
            if(cur == ma){
                pos = min(pos, i[0]);
            }
            if(cur > ma){
                pos = i[0];
                ma = cur;
            }
            
            last = i[1];
        }
        return pos;
    }
};






