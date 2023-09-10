class Solution {
public:    
    const int MOD = 1000000007;

    int countOrders(int n) {
        if (n == 1) {
            return 1;
        }

        // Initialize a vector to store the number of valid sequences for each n
        vector<long long> dp(n + 1, 0);

        // There's only one way to arrange the first pair (pickup, delivery)
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            // For each additional pair, we have 2 choices:
            // 1. Place the new pair after all previous pairs (i.e., between delivery(i-1) and pickup(i+1))
            // 2. Place the new pair between the pickup(i-1) and delivery(i-1) of the last pair
            dp[i] = (dp[i - 1] * (2 * i - 1) * i) % MOD;
        }
        return dp[n];
    }
};

