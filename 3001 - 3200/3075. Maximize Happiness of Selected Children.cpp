// A 1

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long res = 0;
        int cnt = 0;
        for (int i = 0; i < happiness.size(); ++i) {
            res += max(0, happiness[i] - cnt);
            cnt++;
            if(cnt >= k) break;
        }        
        return res;
    }
};
