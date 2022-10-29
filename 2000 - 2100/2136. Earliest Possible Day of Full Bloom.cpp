class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second ; 
    }
    
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int, int>> vp;
        
        for(int i=0; i<p.size(); i++){
            vp.push_back({p[i], g[i]});
        }
        
        sort(vp.begin(), vp.end(), compare);
        int start = 0;
        int ans = 0;
        for(int i=0; i<p.size(); i++){
            start += vp[i].first;
            ans = max(ans, start + vp[i].second);
        }
        
        return ans;    
    }
};

