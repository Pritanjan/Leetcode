// APPROACH 1
// n & (n - 1) drops the lowest set bit. It's a neat little bit trick.
//
// Let's use n = 00101100 as an example. This binary representation has three 1s.
//
// If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.
//
// If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.
//
// If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.
//
// n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n){
            n &= n-1;
            count++;
        }
        return count;
    }
};

// APPROACH 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i=0; i<32; i++){
            if(n%2)
                ans++;
            n = n/2;
        }
        return ans;    
    }
};

// APPROACH 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n){
            // n &= n-1;
            if(n&1)
                count++;
            n = n>>1;
        }
        
        return count;
    }
};

// APPROACH 4
class Solution {
public:
    int hammingWeight(uint32_t n) {
         return __builtin_popcountl(n);
    }
};
