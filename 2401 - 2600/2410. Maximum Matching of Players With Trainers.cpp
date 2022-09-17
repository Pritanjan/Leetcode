// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int cnt = 0;
        int L = 0, R = 0;
        while(L < p.size() and R < t.size()){
            if(p[L] <= t[R]){
                cnt++,L++,R++;
            }
            else
                R++;
        }
        return cnt;            
    }
};




