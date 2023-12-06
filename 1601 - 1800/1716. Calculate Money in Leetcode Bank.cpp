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






// A 2  - Brute Force

int totalMoney(int n) {
    int total = 0;
    int base = 1;
    for (int i = 0; i < n; ++i) {
        total += base + (i % 7);
        if (i % 7 == 6) base += 1;
    }
    return total;
}





// A 3

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int rem  = n % 7;
        int res  = 28 * week + 7 * week * (week - 1) / 2;
        res += (week + 1 + week + rem) * rem / 2;
        return res;
    }
};






// A 4 

