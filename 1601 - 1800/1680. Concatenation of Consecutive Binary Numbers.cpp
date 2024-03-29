// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    // the idea is to use bit manipulation to set the current number based on the previous number
    // for example, 
    // n = 1, ans = 0b1
    // n = 2 (10), we need to shift 2 bits of the previous ans to the left and add `n`
    // i.e. 1 -> 100 (shift 2 bits to the left) -> 110 (set `10`). ans = 0b110
    // n = 3 (11), we need to shift 2 bits of the previous ans to the left and add `n` 
    // i.e 110 -> 11000 (shift 2 bits to the left) -> 11011 (set `11`). ans = 0b11011
    // n = 4 (100), we need to shift 3 bits of the previous ans to the left and add `n`
    // i.e. 11011 -> 11011000 (shift 3 bits to the left) -> 11011100 (set `100). ans = 0b11011100
    // so now we can see a pattern here
    // we need to shift `l` bits of the previous ans to the left and add the current `i` 
    // how to know `l`? it is not difficult to see `x` only increases when we meet power of 2
    int concatenatedBinary(int n) {
        int M = 1e9 + 7, l = 0;
        long ans = 0;
        
        for(int i=1; i<=n; i++){
            if((i & (i-1)) == 0)
                l += 1;
            
            ans = ((ans << l) | i) % M;
        }
        return ans;
    }
};


class Solution {
public:
    int concatenatedBinary(int n) {
        int M = 1e9 + 7, l = 0;
        long ans = 0;
        
        for(int i=1; i<=n; i++){
            l = log(i) / log(2) + 1;
            ans = ((ans << l) | i) % M;
        }
        return ans;
    }
};




