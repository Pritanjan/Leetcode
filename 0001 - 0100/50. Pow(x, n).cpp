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


