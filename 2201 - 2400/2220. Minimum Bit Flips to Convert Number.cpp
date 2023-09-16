// A 1

class Solution {
public:
    int minBitFlips(int a, int b) {
        int n = a ^ b;
        int cnt = 0;        
        while(n != 0) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};


// OR


class Solution {
public:
    int minBitFlips(int a, int b) {
        int n = a ^ b;
        int cnt = 0;        
        while(n > 0) {            
            cnt += n  & 1;   // Check the least significant bit
            n >>= 1;  // Right-shift the result to check the next bit
        }
        return cnt;
    }
};






// A 2 - STL

class Solution {
public:
    int minBitFlips(int a, int b) {
        return __builtin_popcount(a^b);
    }
};





// A 3 

