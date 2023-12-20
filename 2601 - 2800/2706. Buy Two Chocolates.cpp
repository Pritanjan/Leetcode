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

