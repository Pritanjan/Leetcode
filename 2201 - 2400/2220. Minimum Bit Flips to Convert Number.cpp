// A 1 - Bit Manipulation with XOR
// It XORs the two numbers and counts the set bits in the result using a faster bitwise trick:

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
// Bit-by-Bit Comparison
// It compares the corresponding bits of the two numbers from left to right and
// counts the positions where they differ. 
// It stops when the two numbers become the same:

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

