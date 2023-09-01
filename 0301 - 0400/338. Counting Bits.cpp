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


// OR


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i=0; i<=n; i++) {
            int cnt = 0;
            int temp = i;
            while(temp > 0) {
                if(temp & 1) cnt++;
                temp >>= 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};






// A 2 

class Solution {
public:
    int countOne(int n) {
        return __builtin_popcount(n);
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) {
            res.push_back(countOne(i));
        }
        return res;
    }
};






// A 3

