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
// Count the number of set bits in the binary representation of n. If there's only one set bit, 
// then n is a power of 2.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return __builtin_popcount(n) == 1;
    }
};


// OR Count Leading Zeros:
// Use __builtin_clz function for counting leading zeros to check if n is a power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return __builtin_clz(n) + __builtin_ctz(n) == 31;
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
        
        // return pow(2, round(log_val)) == n;
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







// A 6 Recursive Approach:
// Use recursion to repeatedly divide the number by 2 and check if it eventually becomes 1.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        // if(n % 2 == 0) return isPowerOfTwo(n / 2);
        // return false;

        // check if n is a power of two
        return (n & 1) == 0 && isPowerOfTwo(n >> 1);
    }
};






// A 7 - Bitset Approach
// Use bitset class to check if there's only one bit set in the binary representation of n.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        bitset<32> bits(n); // Assuming a 32-bit integer
        return bits.count() == 1;
    }
};






// A 8  -  Bit Shift towards Right
// Do Right-shift the bits of n until it becomes 1, and check if it becomes 1 in the end

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n > 1) {
            if(n % 2 != 0) return false;
            n >>= 1;
            // n /= 2;
        }
        return true;
    }
};






// A 9 - LC Discuss 
// Use the fact that the maximum power of 2 that fits in a 32-bit integer is 2^30.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (1073741824 % n == 0);
    }
};






// A 10 - Use FFS (Find First Set) Function chatgpt
// Use the ffs function from <climits> header to find the position of the least significant set bit
// and check if it's the only bit set.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int pos = ffs(n);
        return n == (1 << (pos - 1));
    }
};






// A 11 

