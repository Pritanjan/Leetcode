// A 1

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int a = 1, b = 2;
        for(int i=3; i<n; i++){
            int t = a + b;
            a = b;
            b = t;
        }
        return a + b;
    }
};






// A 2

