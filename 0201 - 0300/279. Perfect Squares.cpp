// A 1 

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






// A 2 

// According to Lagrange's four-square theorem(please wiki/google), any positive number
// can be represented as 4(at most) square number sum.

// Given a positive integer n, find the least number of perfect square numbers 
// (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, 
// return 2 because 13 = 4 + 9.

// divide by 4, notice that, 2 and 8, 3 and 12, 4 and 16 has the same number of square factors.
// if number%8==7, this result in a square factors 2^2 + 1 +1 +1, which is four.
// if any two numbers can suqare sum to n, return 1 or 2.
// otherwise result is 3.

class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0)  n /= 4;
        if(n % 8 == 7) return 4;
        for(int x=0; x*x <=n; x++){
            int y = sqrt(n - x*x);
            if(x*x + y*y == n){
                if(x == 0 || y == 0) return 1;
                else return 2;
            }
        }
        return 3;
    }
};






// A 3  - recusive

class Solution {
public:
    int numSquares(int n) {
        int res = n, num =2;
        while(num * num <=n){
            int x = n/(num*num), y = n%(num*num);
            res = min(res, x + numSquares(y));
            ++num;
        }
        return res;
    }
};






// A 4 

// using an array dp[], dp[i] means the number need to square-sum up to i, 
// then, for all the j from 1 to i+jj <=n; calculate dp[i+jj] = ?, 
// initially set each dp[i] equals to max.

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=1; i<=n; i++){
            dp[i] = INT_MAX;
        }
        dp[0]=0;
        for(int i=0; i<=n; i++){
            for(int j=1; i+ j*j <=n; j++){
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }

        return dp[n];
    }
};
