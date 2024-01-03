// A 1
// It works by traversing the binary representation of the number from the least significant
// bit to the most significant bit. If the bit is 1, the count is incremented.

class Solution {
public:
    int countOne(int n) {
        int cnt = 0;
        while (n > 0) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) {
            res.push_back(countOne(i));
        }
        return res;
    }
};


// OR


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i=0; i<=n; i++) {
            int cnt = 0;
            int temp = i;
            while(temp > 0) {
                // if(temp & 1) cnt++;
                // temp /= 2;
                
                // cnt += temp % 2;
                // temp >>= 1;

                temp &= (temp - 1);
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};









// A 2  - Using the popcount() function

// The popcount() function is an inbuilt function that counts the number 
// of set bits (1's) in a binary number.
// We can use this function to count the number of 1's in the binary representation of a number
// and return an array of the results as follows:

class Solution {
public:
    int countOne(int n) {
        return __builtin_popcount(n);
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) {
            res.push_back(countOne(i));
        }
        return res;
    }
};






// A 3 - Using DP
// It works by creating a table that stores the number of 1's in the 
// binary representation of the numbers from 0 to n. 
// The table can be constructed recursively or iteratively

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};






// A 4 - Dp memoization 
// It works by storing the results of previously computed subproblems in a table. 
// it help to improve the performance of the algorithm

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if(i & 1) dp[i] = dp[i >> 1] + 1;
            else dp[i] = dp[i >> 1];
        }
        return dp;
    }
};


