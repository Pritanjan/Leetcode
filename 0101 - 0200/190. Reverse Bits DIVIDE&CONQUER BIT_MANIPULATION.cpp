// https://leetcode.com/problems/reverse-bits/

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

// FOR 2nd BIT, RIGHT SHIFT N BY 2 (n>>2) AND TAKE ITS & WITH 1 
// NOW MAEK ith bit form last acc to mask in new no .
