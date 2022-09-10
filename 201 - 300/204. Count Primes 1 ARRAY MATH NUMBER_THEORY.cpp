// https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return false;
        
        vector <bool> sieve(n,false);
        int count = 1;
        int up = sqrt(n);
        
        for(int i=3; i<n; i+=2){
            if(!sieve[i]){
                count++;
                
                if(i > up)
                    continue;
                for(int j=i*i; j<n; j+=i)
                    sieve[j] = true;
            }
        }
        return count;
        
    }
};
