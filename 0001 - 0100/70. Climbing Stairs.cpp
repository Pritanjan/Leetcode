// A 1 - terative Solution 

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int a = 1, b = 2;
        for(int i=3; i<n; i++){
            int t = a + b;
            a = b;
            b = t;
        }
        return a + b;
    }
};






// A 2 - DP (Bottom-Up)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;        
        for(int i=3; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }        
        return dp[n];
    }
};


// OR


class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(3, 0); // We only need three variables: dp[i], dp[i-1], and dp[i-2]
        dp[1] = 1;
        dp[2] = 2;        
        for(int i=3; i<=n; ++i) {
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }        
        return dp[n % 3];
    }
};






// A 3
// It calculates the nth Fibonacci number directly using the closed-form expression
// for the Fibonacci sequence and converts it to an integer.

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return fibn / sqrt5;
    }
};






// A 4  -  Matrix Exponentiation: - ChatGpt

class Solution {
public:
    typedef vector<vector<long long>> Matrix;
    Matrix matrixMultiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        int m = B.size();
        int p = B[0].size();
        
        Matrix C(n, vector<long long>(p, 0));        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<p; ++j) {
                for(int k=0; k<m; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }        
        return C;
    }

    Matrix matrixPower(const Matrix& A, int n) {
        int size = A.size();
        if(n == 1) return A;
        if(n % 2 == 0) {
            Matrix half_pow = matrixPower(A, n / 2);
            return matrixMultiply(half_pow, half_pow);
        } 
        else {
            Matrix half_pow = matrixPower(A, (n - 1) / 2);
            Matrix temp = matrixMultiply(half_pow, half_pow);
            return matrixMultiply(temp, A);
        }
    }

    int climbStairs(int n) {
        if(n <= 2) return n;
        
        Matrix transition = {{1, 1}, {1, 0}};
        Matrix result = matrixPower(transition, n - 1);        
        return result[0][0] + result[0][1];
    }
};






// A 5 

class Solution {
private:
    unordered_map<int, int> memo;

    int calculate(int n) {
        if(n <= 2) return n;
        if(memo.find(n) != memo.end()) return memo[n];
        int result = calculate(n - 1) + calculate(n - 2);
        memo[n] = result;
        return result;
    }
public:
    int climbStairs(int n) {
        return calculate(n);
    }
};






// A 6 

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 1, 0);
        return climbStairs(n, v);
    }
private:
    int climbStairs(int n, vector<int>& v) {
        if(n <= 2) return n;
        if(v[n] != 0) return v[n];

        v[n] = climbStairs(n-1, v) + climbStairs(n-2, v);
        return v[n];
    }
};






// A 7 

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        
        return (pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5;
    }
};






// A 8
// calculate the binomial coefficient for each possible number of 2-step climbs (0 to n/2) and 
// sum them up to find the total number of distinct ways to climb the stairs.

class Solution {
public:
    // Function to calculate the binomial coefficient (n choose k)
    long long binomialCoefficient(int n, int k) {
        if(k == 0 || k == n) return 1;
                
        long long res = 1;
        k = min(k, n - k); // Use the smaller of k and n-k for efficiency
        for(int i=0; i<k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    int climbStairs(int n) {
        int res = 0;
        for(int i=0; i<=n / 2; ++i) {
            res += binomialCoefficient(n - i, i);
        }
        return res;
    }
};






// A 9

class Solution {
public:
    vector<int> v; // Memoization table to store computed results
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        // Check if the result for 'n' has already been computed
        if(v.size() <= n) v.resize(n+1, -1);
        else if(v[n] != -1) return v[n];

        // Compute the result for 'n' by recursively calculating the subproblems
        int ways = climbStairs(n-1) + climbStairs(n-2);

        // Store the computed result in the memoization table
        v[n] = ways;
        return ways;
    }
};






// A 10

