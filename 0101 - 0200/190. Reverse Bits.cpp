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






// A 3

