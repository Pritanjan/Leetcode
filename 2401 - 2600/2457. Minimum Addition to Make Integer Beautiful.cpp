#define ll long long 
class Solution {
public:
    ll int FS(ll int n){
        ll int sum = 0;
        while(n){
            sum += n % 10;
            n = n/10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        ll int m = n;
        ll int base = 1;
        
        while(FS(n) > target){
            n = n/10 + 1;
            base *= 10;
        }
        return n*base - m;
    }
};







