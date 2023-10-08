// A 1 

class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        int n = pt.size();
        int m = t.size();
        
        sort(pt.begin(), pt.end()); 
        sort(t.rbegin(), t.rend()); 
        int mt = 0;
        for(int i=0; i<n; ++i) {
            int nt = pt[i] + t[i * 4];
            mt = max(mt, nt);
        }

        return mt;
    }
};

