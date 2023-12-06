// A 1 

class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int mon = 1;
        while(n > 0) {
            for(int d=0; d<min(n, 7); d++) {
                ans += mon + day;
            }
            
            n -= 7;
            mon++;
        }        
        return ans;
    }
};






// A 2 

