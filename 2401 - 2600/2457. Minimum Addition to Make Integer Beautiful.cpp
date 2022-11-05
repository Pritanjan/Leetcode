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


//     if(digsum(n)<=target)return 0;
//         long long count=10;
//         long long temp=n;
        
//         while(digsum(temp)> target){
//             long long mod=n%count;
//              temp=n+count-mod;
            
//             count*=10;
//         }
//         return temp-n;



// class Solution {
// public:
//     long long makeIntegerBeautiful(long long n, int target) {
//         long long t = 10;
//         if(calc(n) <= target) return 0;
//         for(;t <= n* 100;t*=10){
//             if(calc(n+(t-n%t)) <= target) return t-n%t;
//         }
//         return -1;
//     }
// };
