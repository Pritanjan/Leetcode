// A 1 
// FOR 2nd BIT, RIGHT SHIFT N BY 2 (n>>2) AND TAKE ITS & WITH 1 
// NOW MAEK ith bit form last acc to mask in new no .

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rev = 0;
        for(int i=0; i<32; i++){
            int mask = 1 & (n>>i) ;
            rev = rev | mask<<(31-i) ;
        }
        return rev;
    }
};






// A 2

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int bitPos = 31; // 32-bit integer, so we start from the leftmost bit (position 31)
        while(n > 0) {
            // Get the rightmost bit of 'n' using bitwise AND
            uint32_t rightmostBit = n & 1;

            // Shift the rightmost bit to the left by 'bitPos' positions
            rightmostBit <<= bitPos;
            
            // Set the corresponding bit in 'result' to the rightmost bit
            res |= rightmostBit;

            // Shift 'n' to the right to process the next bit
            n >>= 1;
            // Decrement 'bitPos' to move to the next bit position
            bitPos--;
        }
        return res;
    }
};






// A 3  -  Divide-and-conquer 
// a. We use bitwise operations to swap adjacent pairs of bits, then nibbles (4-bit groups), and
//    finally bytes (8-bit groups). This is done in a series of shifts and masks.
// b. The key idea is to reverse the bits in smaller chunks and then combine them to obtain the final result.
    
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Swap adjacent pairs of bits, then nibbles, and finally bytes.
        n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
        n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
        n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
        n = ((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8);
        n = ((n >> 16) & 0x0000FFFF) | ((n & 0x0000FFFF) << 16);
        return n;
    }
};






// A 4
// initialize reversed to 0 to accumulate the reversed bits.
// We iterate through the 32 bits of the input n in a loop.
// In each iteration, we left-shift the reversed number by 1 bit to make room for the next bit.
// We set the least significant bit of reversed to the current bit of n using bitwise OR (|).
// We right-shift n by 1 bit to process the next bit.
// Repeat steps 3-5 for all 32 bits.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for(int i=0; i<32; ++i) {  
            // Left shift the reversed number to make room for the next bit.
            rev <<= 1;    
            // Set the least significant bit of reversed to the current bit of n.
            rev |= (n & 1);  
            // Right shift n to process the next bit.
            n >>= 1;            
        }
        return rev;
    }
};






// A 5

