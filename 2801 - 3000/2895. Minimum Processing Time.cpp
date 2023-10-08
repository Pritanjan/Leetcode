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


// OR


class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        sort(pt.begin(), pt.end());
        sort(t.begin(), t.end(), [](const int a, const int b) { return a > b; });
        int l = 0, ans = 0;
        for(int st : pt) {
            int curr = 0, cnt = 0;
            while(l < t.size() && cnt < 4) {
                curr = max(curr, st + t[l]);
                l++;
                cnt++;
            }
            ans = max(ans, curr);
        }        
        return ans;
    }
};






// A 2


