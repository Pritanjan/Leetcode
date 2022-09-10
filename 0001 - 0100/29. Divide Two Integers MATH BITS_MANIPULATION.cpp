class Solution {
public:
    typedef long long int ll;
    int divide(ll dividend, ll divisor) {
        ll count = 0;
        div = llabs(dividend);
        dis = llabs(divisor);
        
        if(divisor == 1)
        	return dividend;
    	if(dividend == INT_MIN && abs(divisor) == 1)
        	return INT_MIN;
        
        while(div>=dis){
            ll a = dis;
            ll m = 1;
            while((a<<1) < dividend){
                a<<=1;
                m<<=1;
            }
            count+=m;
            div-=a;
        }
        
        if((div<0 && dis>0) || (div>0 && dis<0))
            return -count;
        else
            return count;
        
        
    }
};
