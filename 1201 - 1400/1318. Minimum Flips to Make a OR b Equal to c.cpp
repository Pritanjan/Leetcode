// A 1 

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            int bitA = a & 1;        // Get the rightmost bit of a
            int bitB = b & 1;        // Get the rightmost bit of b
            int bitC = c & 1;        // Get the rightmost bit of c
            if ((bitA | bitB) != bitC) {
                flips += (bitC == 1) ? 1 : (bitA + bitB);
                    // Flip any one bit of a or b     // Flip both bits of a and b
            }
            a >>= 1;  // Shift right to get the next bit of a
            b >>= 1;  // Shift right to get the next bit of b
            c >>= 1;  // Shift right to get the next bit of c
        }
        return flips;
    }
};






// A 2

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mx = max({a, b, c});
        int x, y, ans = 0;
        while(mx > 0) {
            x = a % 2, y = b % 2;
            if(c & 1) {
                if(x == 0 && y == 0) ans++;
            } 
            else {
                if(x == 1) ans++;
                if(y == 1) ans++;
            }
            a /= 2, b /= 2, c /= 2, mx /= 2;
        }
        return ans;
    }
};






// A 3 

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i=0; (1<<i) <= max(max(a, b), c); i++) {
            int check = 1<<i;
            int bitA = a & check ? 1 : 0;
            int bitB = b & check ? 1 : 0;
            int bitC = c & check ? 1 : 0;

            if(bitC == 1) {
                if(bitA == 0 && bitB == 0) ans++;
            }
            else if(bitC == 0) {
                if(bitA == 1 && bitB == 1) ans += 2;
                else if(bitA == 1 || bitB == 1) ans++;
            }
        }
        return ans;
    }
}; 






// A 4 

