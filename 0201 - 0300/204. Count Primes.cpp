// A 0 - Brute Force - TLE

class Solution {
public:
    bool isPrime(int num) {
        if(num <= 1) return false;
        for(int i=2; i*i<=num; ++i) {
            if(num % i == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for(int i=2; i<n; ++i) {
            if(isPrime(i)) ++count;
        }
        return count;
    }
};





// A 1

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector <bool> sieve(n,true);
        for(int i=2; i<n; i++){
            if(sieve[i]) {
                count++;
                int k = 2;
                while(k * i < n) {
                    sieve[k*i] = false;
                    k++;
                }
            }
        }
        return count;        
    }
};


class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return false;
        vector <bool> sieve(n+1,false);
        int count = 1;
        int up = sqrt(n);        
        for(int i=3; i<n; i+=2) {
            if(!sieve[i]) {
                count++;
                if(i > up) continue;
                for(int j=i*i; j<n; j+=i) sieve[j] = true;
            }
        }
        return count;
        
    }
};


class Solution {
public:
    int countPrimes(int n) {
        vector <bool> sieve(n+1,true);
        int count = 0;
        sieve[0] = sieve[1] = false;
        
        for(int i=2; i<n; i++){
            if(sieve[i]){
                count++;
                for(int j=2*i; j<n; j+=i) sieve[j] = false;
            }
        }
        return count;        
    }
};

// T.C. --> n log(log(n))






// A 2 

