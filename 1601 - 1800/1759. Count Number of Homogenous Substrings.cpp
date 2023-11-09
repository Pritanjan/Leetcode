// A 1

class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int res = 0;
        int cnt = 0;

        for(int i=0; i<s.size(); i++) {
            if(i == 0 or s[i] == s[i-1]) cnt++;
            else cnt = 1;

            res = (res + cnt) % MOD;
        }
        return res;        
    }
};






// A 2 

