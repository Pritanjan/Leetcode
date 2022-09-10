//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/2346634/C%2B%2B-2-Solution-with-Explanation

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


class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int maxPr = 0;
        int L = 0;
        int R = 1;
        while(R < pr.size()){
            if(pr[L] < pr[R])
                maxPr = max(maxPr, pr[R] - pr[L]);
            else
                L = R;
            
            R++;
        }
        return maxPr;
    }
};
