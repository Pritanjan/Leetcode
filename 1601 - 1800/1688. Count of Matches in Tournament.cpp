// A 1 

class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};




// A 2

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1) {
            if(n % 2 == 0) {
                ans += n / 2;
                n /= 2;
            }
            else {
                ans += (n-1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return ans;
    }
};





// A 3  -  Iterative Solution

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1) {
            ans += n / 2;
            n = (n + 1) / 2; // Advance to the next round
        }
        return ans;
    }
};





// A 4 - Recursive solution

class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;
        return n / 2 + numberOfMatches((n + 1) / 2);
    }
};


// OR


class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;
        else if(n % 2 == 0) return n / 2 + numberOfMatches(n / 2);
        else return (n - 1) / 2 + numberOfMatches((n + 1) / 2);
    }
};






// A 5 Bit Manipulation

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1) {
            ans += n >> 2;
            n = (n + 1) >> 2; // Advance to the next round
        }
        return ans;
    }
};





// A 6 

