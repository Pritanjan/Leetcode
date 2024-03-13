// A 1 - Brute Force

class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; ++x) {
        int leftSum = 0, rightSum = 0;
        for (int i = 1; i <= x; ++i) leftSum += i;
        for (int i = x; i <= n; ++i) rightSum += i;
        if (leftSum == rightSum) return x;
    }
    return -1;
    }
};






// A 2 

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n+1) / 2;
        int pivot = sqrt(sum);
        return pivot * pivot == sum ? pivot : -1;
    }
};






// A 3 - Prefix Sum Array:

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + i;
        }            

        for (int x = 1; x <= n; ++x) {
            int leftSum = prefixSum[x];
            int rightSum = prefixSum[n] - prefixSum[x - 1];
            if (leftSum == rightSum) return x;
        }
        return -1;
    }
};


