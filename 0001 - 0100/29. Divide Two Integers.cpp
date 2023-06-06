// APPROACH 1


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)  return INT_MAX;
        
        long long count = 0; 
        long long int div  = abs(dividend);
        long long int dis  = abs(divisor);
        long long int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
//         if(div==dis) return sign*1;
        
        while(div >= dis) {
            long long int temp = dis, m=1;
            while((temp<<1) <= div) {
                temp<<=1;
                m<<=1;
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







// APPROACH 2


class Solution {
public:
    typedef long long int ll;
    int divide(ll dividend, ll divisor) {
        ll count = 0;
        div = llabs(dividend);
        dis = llabs(divisor);
        
        if(divisor == 1) return dividend;
    	if(dividend == INT_MIN && abs(divisor) == 1) return INT_MIN;
        
        while(div >= dis) {
            ll a = dis;
            ll m = 1;
            while( (a << 1) < dividend) {
                a <<= 1;
                m <<= 1;
            }
            count += m;
            div -= a;
        }
        
        if( (div < 0 && dis > 0) || (div > 0 && dis < 0)) return -count;
        else return count;        
    }
};

