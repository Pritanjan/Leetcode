// A 1 - // Brute Force Iteration

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0; 
        int num2 = 0;
        for(int i=1; i<=n; i++) {
            if(i % m != 0) num1 += i; 
            else num2 += i;
        }
        return num1 - num2;
    }
};






// A 2 -  Use Arithmetic Series Formula

class Solution {
public:
    long long differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int d = n / m;
        int sumDivisible = (m * d * (d + 1)) / 2;
        int sumNotDivisible = totalSum - sumDivisible;
        return sumNotDivisible - sumDivisible;
    }
};








// A 3


 // Bit Manipulation
    int differenceOfSums8(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & m) == 0) {
                num1 += i;
            } else {
                num2 += i;
            }
        }
        return num1 - num2;
    }

    // Dynamic Programming
    int differenceOfSums9(int n, int m) {
        int dpNotDivisible[n + 1], dpDivisible[n + 1];
        dpNotDivisible[0] = dpDivisible[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                dpDivisible[i] = dpDivisible[i - 1] + i;
                dpNotDivisible[i] = dpNotDivisible[i - 1];
            } else {
                dpDivisible[i] = dpDivisible[i - 1];
                dpNotDivisible[i] = dpNotDivisible[i - 1] + i;
            }
        }
        return dpNotDivisible[n] - dpDivisible[n];
    }

    // Sieve of Eratosthenes (For Prime Divisors of m)
    int differenceOfSums10(int n, int m) {
        // Implement Sieve of Eratosthenes to find prime divisors of m
        // Calculate num1 and num2 based on prime divisors
        int num1 = 0, num2 = 0;
        return num1 - num2;
    }




// Recursion (Recursive Helper Function)
    int sumNotDivisible(int n, int m) {
        if (n == 0) {
            return 0;
        }
        if (n % m != 0) {
            return n + sumNotDivisible(n - 1, m);
        }
        return sumNotDivisible(n - 1, m);
    }

    int sumDivisible(int n, int m) {
        if (n == 0) {
            return 0;
        }
        if (n % m == 0) {
            return n + sumDivisible(n - 1, m);
        }
        return sumDivisible(n - 1, m);
    }

    int differenceOfSums6(int n, int m) {
        return sumNotDivisible(n, m) - sumDivisible(n, m);
    }





