class Solution {
public:
    bool prime(int n) {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        
        int i = 5;
        while(i * i <= n) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
            i += 6;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i=0; i<n; i++) {
            if(prime(nums[i][i])) p = max(p, nums[i][i]);
            if(prime(nums[i][n-i-1])) p = max(p, nums[i][n-i-1]);
        }
        return p;
    }
};





