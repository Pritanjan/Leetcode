// APPROACH 1


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









// APPROACH 2


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








// APPROACH 3



