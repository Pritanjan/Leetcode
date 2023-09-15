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
    typedef std::vector<std::vector<long long>> Matrix;

    Matrix matrixMultiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        int m = B.size();
        int p = B[0].size();
        
        Matrix C(n, std::vector<long long>(p, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < m; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return C;
    }

    Matrix matrixPower(const Matrix& A, int n) {
        int size = A.size();
        if (n == 1) {
            return A;
        }
        
        if (n % 2 == 0) {
            Matrix half_pow = matrixPower(A, n / 2);
            return matrixMultiply(half_pow, half_pow);
        } else {
            Matrix half_pow = matrixPower(A, (n - 1) / 2);
            Matrix temp = matrixMultiply(half_pow, half_pow);
            return matrixMultiply(temp, A);
        }
    }

    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        Matrix transition = {{1, 1}, {1, 0}};
        Matrix result = matrixPower(transition, n - 1);
        
        return result[0][0] + result[0][1];
    }
};






// A 5 

class Solution {
private:
    std::unordered_map<int, int> memo;

    int calculate(int n) {
        if (n <= 2) {
            return n;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
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






