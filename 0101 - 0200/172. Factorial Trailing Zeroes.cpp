//https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int a = 0;
        for(int i=1; i<=n; i++){
            // a = a * i;    // Factorial
            a += floor(n/pow(5,i));
        }
        // cout << a;
        return a;
    }
};
