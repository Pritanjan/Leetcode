class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> v = h;
        // for(auto i : h) {
        //     v.push_back(i);
        // }
        sort(h.begin(), h.end());
        int cnt = 0;
        for(int i = 0; i < h.size(); i++){
            if(h[i] != v[i]) cnt++;
        }
        return cnt;
    }
};

