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





// A 3 Conversion to Binary Strings
// We convert both a and b to binary strings and count the positions where they differ.

class Solution {
public:
    int minBitFlips(int a, int b) {
        string a1 = bitset<32>(a).to_string();
        string b1 = bitset<32>(b).to_string();
        int cnt = 0;
        for(int i=0; i<32; i++) {
            if(a1[i] != b1[i]) cnt++;
        }    
        return cnt;
    }
};






// A 4 -  Count the number of bits to be flipped to convert A to B using the AND operator - gfg
// Start comparing the bits in A and B, starting from the least significant bit and
// if (A & 1) is not equal to (B & 1) then the current bit needs to be flipped, 
// as the value of bits is different at this position in both the numbers

// 1. Declare variable flips equal to zero
// 2. Run a loop, while a is greater than zero and b is also greater than zero
//    -  Calculate values of (A AND 1) and (B AND 1)
//    -  If these values are not equal then increase the flip value by 1
//    - Right shift a and b by 1
// 3. Return flips

class Solution {
public:
    int minBitFlips(int a, int b) {
        // initially flips is equal to 0
        int flips = 0;
        // each bits of a && b with 1 and store them if t1 and t2 
        // if t1 != t2 then we will flip that bit
        while(a > 0 || b > 0) {
            int t1 = (a & 1);
            int t2 = (b & 1);
            if(t1 != t2) flips++;
            // right shifting a and b
            a >>= 1;
            b >>= 1;
        }    
        return flips;
    }
};





// A 5
