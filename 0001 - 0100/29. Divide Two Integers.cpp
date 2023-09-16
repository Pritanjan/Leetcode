// A 1

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)  return INT_MAX;
        
        long long count = 0; 
        long long int div  = abs(dividend);
        long long int dis  = abs(divisor);
        long long int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        // if(div == dis) return sign*1;
        
        while(div >= dis) {
            long long int temp = dis, m=1;
            while((temp << 1) <= div) {
                temp <<= 1;
                m <<= 1;
            }
            div -= temp;
            count += m;
        }
        return sign*count;
    }
};

//               expected     wants
//   1^ 1   =       1           1
//   1^-1   =       1          -1
//  -1^ 1   =      -1          -1
//  -1^-1   =      -1           1






// A 2

class Solution {
public:
    typedef long long int ll;
    int divide(ll dividend, ll divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return (dividend);
        if(divisor == -1) {
            if(dividend == INT_MIN) return INT_MAX; // Overflow case
            return -(dividend);
        }
        
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        ll div = llabs(dividend);
        ll dis = llabs(divisor);
        ll cnt = 0;
        while(div >= dis) {
            ll temp = dis;
            ll m = 1;
            while(div >= (temp << 1)) {
                temp <<= 1;
                m <<= 1;
            }
            div -= temp;
            cnt += m;
        }
        return isNegative ? -(cnt) : (cnt);
    }
};





// A 3

