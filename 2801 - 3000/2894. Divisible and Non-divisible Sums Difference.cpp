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








// A 3  - dp

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int NotDiv[n+1], Div[n + 1];
        NotDiv[0] = Div[0] = 0;
        for(int i=1; i<=n; i++) {
            if(i % m == 0) {
                Div[i] = Div[i-1] + i;
                NotDiv[i] = NotDiv[i-1];
            } 
            else {
                Div[i] = Div[i-1];
                NotDiv[i] = NotDiv[i-1] + i;
            }
        }
        return NotDiv[n] - Div[n];
    }
};
    
   




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





