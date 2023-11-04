// A 1

class Solution {
public:
    int getLastMoment(int n, vector<int>& L, vector<int>& R) {
        int mxL = 0;
        int mxR = n;

        if(!L.empty()) mxL = *max_element(L.begin(), L.end());
        if(!R.empty()) mxR = *min_element(R.begin(), R.end());

        return max(mxL, n - mxR);        
    }
};






// A 2 

class Solution {
public:
    int getLastMoment(int n, vector<int>& L, vector<int>& R) {
        int res = 0;
        for(auto num : L) res = max(res, num);
        for(auto num : R) res = max(res, n - num);
        return res;
    }
};






// 
