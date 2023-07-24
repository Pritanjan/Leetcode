class Solution {
public:
    double myPow(double x, int n) {
	if(n == 0) return 1;    
        if(n <  0) return 1/x * myPow(1/x, -(n+1));        
        return (n % 2 == 0) ? myPow(x*x, n/2 ) : x*myPow(x*x, n/2);
    }
};




// OR



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
            if(exponent % 2 == 1)
                res = fmod(res * base, mod);
            base = fmod(base * base, mod);
            exponent = exponent / 2;
        }
        return res;
    }
};



// OR

class Solution {
public:
    int mod = 1e9 + 7;
    double myPow(double x, long long n) {
        // Handle negative exponent separately to avoid overflow with -INT_MIN
        if(n < 0) {
            x = 1 / x;
            n = -n;
        }
        return f(x, n);
    }

    double f(double base, long long exponent) {
        double res = 1;
        while(exponent > 0) {
            // If exponent is odd, multiply the result with base
            if(exponent % 2 == 1) res *= base;

            // Reduce the power of base and double the result
            base *= base; 
            exponent /= 2;
        }
        return res;
    }
};






class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        int sign = (n>0)?1:-1;
        long long exp =( long long)n * sign;//avoid of overflow for n=INT_MIN change sign 
        bitset<32> bexp(exp);
        double a = 1;
        x = (sgn == 1) ? x : 1.0 / x;
        for(int b=31; b>=0; b--){
            a = a*a;
            if(bexp[b]) a *= x;
        }
        return a;
    }
};




