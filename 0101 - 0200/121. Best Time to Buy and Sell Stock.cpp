// APPROACH 0 - BRUTE FORCE TLE

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mx_pr = 0;
        for(int i=0; i<p.size(); i++){
            for(int j=i; j<p.size(); j++){
                int profit = (p[j] - p[i]);
                if(profit > mx_pr) 
                    mx_pr = profit;
            }
        }
        return mx_pr;
    }
};






// APPROACH 1 [ One Pass Approach ]

class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int mi  = INT_MAX;
        int ans = 0;
        for(int i=0; i<pr.size(); i++){
            mi  = min(mi, pr[i]);
            ans = max(ans, pr[i] - mi) ;
        }
        return ans;
    }
};

// The approach is to iterate through the prices and keep track of the minimum price
// seen so far and the maximum profit seen so far.
// We update the minimum price if we see a lower price, and
// update the maximum profit if we see a higher price that yields a larger profit
// than the current maximum profit. 
// Finally, we return the maximum profit.

// T.C. --> O(n), where n is the size of the input array.





// APPROACH 2

class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int maxPr = 0;
        int L = 0;
        int R = 1;
        while(R < pr.size()) {
            if(pr[L] < pr[R]) maxPr = max(maxPr, pr[R] - pr[L]);
            else L = R;
            
            R++;
        }
        return maxPr;
    }
};





// APPROACH 3 [ DP ]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size();
        vector<int> dp(n, 0);
        int minPrice = prices[0];
        
        for(int i=1; i<n; ++i) {
            dp[i] = max(dp[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }        
        return dp[n - 1];
    }
};





// APPROACH 4 Kadane's Algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0;
        int maxSoFar = 0;
        int n = prices.size();
        
        for(int i=1; i<n; ++i) {
            maxCur = max(0, maxCur + prices[i] - prices[i-1]);
            maxSoFar = max(maxSoFar, maxCur);
        }        
        return maxSoFar;
    }
};





// APPROACH 5 [ DIVDE 7 CONQUER ]

class Solution {
public:
    int Helper(vector<int>& prices, int L, int R) {
        if (L >= R) return 0;

        int mid = L + (R - L) / 2;

        int LMxProfit = Helper(prices, L, mid);
        int RMxProfit = Helper(prices, mid + 1, R);

        int miPrice = *min_element(prices.begin() + L, prices.begin() + mid + 1);
        int mxPrice = *max_element(prices.begin() + mid + 1, prices.begin() + R + 1);

        int crossMaxProfit = max(0, mxPrice - miPrice);

        return max({LMxProfit, RMxProfit, crossMaxProfit});
    }

    int maxProfit(vector<int>& prices) {
        return Helper(prices, 0, prices.size() - 1);
    }
};





