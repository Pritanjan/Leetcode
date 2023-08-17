// APPROACH 1

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


