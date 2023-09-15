// A 1

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1073741824) return true;
        for(int i=0; i<30; i++) {
            if(n == pow(2,i)) return true;
        }
        return false;
    }
};






// A 2 - Bit ManiPaulation
// A power of two in binary form always has only one bit set to 1 (e.g., 2 = 0010, 4 = 0100, 8 = 1000).
// WE can use the bitwise AND operator to check if there's only one bit set.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;        
    }
};






// A 3 -  Counting Set Bits:
// Count the number of set bits in the binary representation of n. If there's only one set bit, then n is a power of 2.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return __builtin_popcount(n) == 1;
    }
};


// OR


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count == 1;
    }
};







// A 4 - Logarithmic Approach:
// You can use logarithms to check if log2(n) is an integer. If it is, then n is a power of 2.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double log_val = log2(n);
        return log_val == int(log_val);
    }
};





// A 5 - Check if the number is divisible:
// A power of two is always divisible by 2. You can repeatedly divide n by 2 until it's no longer divisible and check if the result is 1.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};







// A 6 Lookup Table:
// Create a lookup table with known powers of two and check if n matches any of them.
    
class Solution {
public:
    bool isPowerOfTwo(int n) {
        static unordered_set<int> powers_of_two = {1, 2, 4, 8, 16, 32, /* add more as needed */};
        return powers_of_two.find(n) != powers_of_two.end();
    }
};


