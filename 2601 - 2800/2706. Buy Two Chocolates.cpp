// A 0 

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int minCost = INT_MAX;
                
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int cost = prices[i] + prices[j];
                if(cost < minCost) {
                    minCost = cost;
                }
            }
        }
        if(minCost <= money) return money - minCost;
        else return money;
    }
};






// A 1 

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int p = prices[1] + prices[0];
        if(p > money) return money;
        else return money - p;
    }
};






// A 2

