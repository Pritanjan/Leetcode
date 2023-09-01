// A 1

class Solution {
public:
    int countOne(int n) {
        int cnt = 0;
        while (n > 0) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) {
            res.push_back(countOne(i));
        }
        return res;
    }
};






// A 2 

