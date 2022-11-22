class Solution {
public:
    int numSquares(int n) {
        int ans = n;
        for(int i=2; i*i<=n; i++){
            int x = n / (i*i);
            int y = n % (i*i);
            
            ans = min(ans, x + numSquares(y));
        }
        return ans;
    }
};







