// A 0 - Simulation - TLE

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





// A 1 - Bit Manipulation

class Solution {
public:
    int rangeBitwiseAnd(int L, int R) {
        while (L < R) {
            R &= (R - 1);
        }
        return R;
    }
};






// A 2  - Recurstion

class Solution {
public:
    int rangeBitwiseAnd(int L, int R) {
        if(R > L) return (rangeBitwiseAnd(L >> 1, R >> 1) << 1);
        return L;
    }
};






// A 3 - Shiftting

class Solution {
public:
    int rangeBitwiseAnd(int L, int R) {
        int shift = 0;
        while(L < R) {
            L >>= 1;
            R >>= 1;
            ++shift;
        }
        return L << shift;
    }
};

