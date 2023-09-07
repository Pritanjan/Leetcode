// APPROACH 0 [ Brute Force Iteration ] = TLE
// This approach involves multiplying x by itself n times

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long absN = abs((long long)n); // Convert n to long long to handle INT_MIN
        for(long long i=0; i<absN; ++i) res *= x;
        return (n < 0) ? 1.0 / res : res;
    }
};


// OR
// Iterative Binary Exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        
        long long absN = abs(static_cast<long long>(n));
        double res = 1.0;
        while(absN > 0) {
            if(absN % 2 == 1) {
                res *= x;
            }
            x *= x;
            absN /= 2;
        }        
        return (n < 0) ? 1.0 / res : res;
    }
};




// APPROACH 1

class Solution {
public:
    double myPow(double x, int n) {
	if(n == 0) return 1;    
        if(n <  0) return 1/x * myPow(1/x, -(n+1));        
        return (n % 2 == 0) ? myPow(x*x, n/2 ) : x*myPow(x*x, n/2);
    }
};





// APPROACH 2

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;  // Any number to the power of 0 is 1.
        if(n == 1) return x;    // Any number to the power of 1 is itself.
        if(n < 0) {
            x = 1 / x;          // If n is negative, invert x.
            // Handle the case of INT_MIN to avoid overflow.
            if(n == INT_MIN) {
                x *= x;
                n /= 2;
            }
            n = -n;
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};






// APPROACH 3

class Solution {
public:
    int mod = 1e9 + 7;
    double myPow(double x, long long n) {
        if(n < 0) {
            x = 1 / x;
            n = -n;
        }
        return f(x, n);
    }

    double f(double base, long long exponent) {
        double res = 1;
        while(exponent > 0) {
            if(exponent % 2 == 1) res = fmod(res * base, mod);
            base = fmod(base * base, mod);

     //        // If exponent is odd, multiply the result with base
     //        if(exponent % 2 == 1) res *= base;

     //        // Reduce the power of base and double the result
     //        base *= base; 
		
            exponent = exponent / 2;
        }
        return res;
    }
};





// APPROACH 4

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        int sign = (n > 0) ? 1 : -1;
        long long exp = (long long) n * sign; //avoid of overflow for n=INT_MIN change sign 
        bitset<32> bexp(exp);
        double a = 1;
        x = (sign == 1) ? x : 1.0 / x;
        for(int b=31; b>=0; b--){
            a = a*a;
            if(bexp[b]) a *= x;
        }
        return a;
    }
};


