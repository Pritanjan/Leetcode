// A 1

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        int prev = 0;
        int ans = 0;
        for(int i=0; i<m; ++i) {
            int cnt = 0;
            for(int j=0; j<n; ++j) {
                if(bank[i][j] == '1') {
                    cnt++;
                }
            }
            if(cnt != 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};






// A 2 

