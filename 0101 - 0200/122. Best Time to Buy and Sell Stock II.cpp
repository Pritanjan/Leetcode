// APPROACH 1 [ BRUTE FORCE - TLE ]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfitHelper(prices, 0, prices.size() - 1);
    }    
private:
    int maxProfitHelper(vector<int>& prices, int start, int end) {
        if(start >= end) return 0;
        
        int maxProfit = 0;
        for(int i=start; i<end; i++) {
            for(int j=i+1; j<=end; j++) {
                if(prices[j] > prices[i]) {
                    int currProfit = (prices[j] - prices[i]) + maxProfitHelper(prices, start, i-1) + maxProfitHelper(prices, j+1, end);
                    maxProfit = max(maxProfit, currProfit);
                }
            }
        }        
        return maxProfit;
    }
};


// T.C. --> O(N^2)
// S.C. --> O(N)







// APPROACH 2

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int ans = 0;
        for(int i=0; i<n-1; i++) if(p[i] < p[i+1]) ans += p[i+1] - p[i];
        return ans;
    }
};





// APPROACH 3 [ 2 POINTER ]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int st = prices[0], end = prices[0];
        for(int i=1; i<n; i++){
            if(prices[i] > prices[i-1]) end = prices[i];
            else {
                ans += end - st;
                st = prices[i];
                end = st;
            }
        }
        ans += end - st;
        return ans;
    }
};

