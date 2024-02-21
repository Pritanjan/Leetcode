// A 1 - Simulation - TLE

class Solution {
public:
    int rangeBitwiseAnd(int L, int R) {
        int res = INT_MAX;
        for(int i=L; i<=R; i++) {
            res &= i;
        }
        return res;
    }
};





// A 2 - Bit Manipulation

class Solution {
public:
    int rangeBitwiseAnd(int L, int R) {
        while (L < R) {
            R &= (R - 1);
        }
        return R;
    }
};






// A 3 

