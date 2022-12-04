class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int L = 0;
        int R = n - 1;
        long long sum = 0, ans = 0;
        
        sum = s[0] + s[n-1];
        
        while(L <= R){
            if(sum != (s[L] + s[R]))
                return -1;
            
            ans += (s[L] * s[R]);
            L++;
            R--;
        }
        
        return ans;
    }
};
