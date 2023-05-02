// APPROACH 1 [ Brute Force ]


class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
            }
        }
        return k <= factors.size() ? factors[k - 1] : -1;
    }
};






 
// APPROACH 2 [ Optimized Brute Force ]


class Solution {
public:       
    int kthFactor(int n, int k) {
        // iterate from 1 to n and count the factors
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(n % i == 0) {
                cnt++;
                if(cnt == k) {
                    return i;
                }
            }
        }
        return -1; // if there are less than k factors, return -1
    }
};




// OR




class Solution {
public:
    int kthFactor(int n, int k) {
        int i;
        for(i=1; i<=n/2; i++) {
            if(n % i == 0) {
                k--;
                if(k == 0) {
                    return i;
                }
            }
        }

        if(k == 1) return n;
        else return -1;
    }
};







// APPROACH 3 [ Square Root Optimization ]


class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / i != i) {
                    factors.push_back(n / i);
                }
            }
        }
        sort(factors.begin(), factors.end());
        return k <= factors.size() ? factors[k - 1] : -1;
    }
};




// APPROACH 4 [ Square Root Optimization with Early Return ]


class Solution {
public:
    int kthFactor(int n, int k) {
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; i++) {
            if (n % i == 0) {
                k--;
                if (k == 0) {
                    return i;
                }
            }
        }
        if (sqrt_n * sqrt_n == n) {
            k++;
        }
        for (int i = sqrt_n; i >= 1; i--) {
            if (n % i == 0) {
                k--;
                if (k == 0) {
                    return n / i;
                }
            }
        }
        return -1;
    }
};



