class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ust(banned.begin(), banned.end());
        int cnt = 0;
        for(int i=1; i<=n; ++i) {
            if(ust.count(i) == 0 && maxSum >= i) {
                ++cnt;
                maxSum -= i;
            }   
        }
        return cnt;
    }
};

