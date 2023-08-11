// APPROACH 0 Brute Force with Bitmasking

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int Cnt = 0;
        
        for(int j=0; j<(1 << n); ++j) {
            int mi = INT_MAX, mx = INT_MIN;
            for(int i=0; i<n; ++i) {
                if((j >> i) & 1) {
                    mi = min(mi, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            if(mi + mx <= target) {
                cnt = (cnt+1) % MOD;
            }
        }        
        return cnt;
    }
};





// APPROACH 1 Sorting and Two Pointers

class Solution {
public:          
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0, right = n - 1;
        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                ans = (ans + modPow(2, right - left, MOD)) % MOD;
                left++;
            } 
            else {
                right--;
            }
        }
        return ans;
    }

private:
    int modPow(long long base, int exponent, int modulus) {
        int result = 1;
        while(exponent > 0) {
            if(exponent % 2 == 1) {
                result = (result * base) % modulus;
            }
            
            base = (base * base) % modulus;
            exponent /= 2;
        }
        return result;
    }
};


// OR


class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int L = 0, R = n-1;
        long long ans = 0;
        
        vector<int> powers(n, 1);
        for(int i=1; i<n; ++i) {
            powers[i] = (powers[i-1] * 2) % MOD;
        }
        
        while(L <= R) {
            if(nums[L] + nums[R] <= target) {
                ans = (ans + powers[R-L]) % MOD;
                L++;
            } 
            else {
                R--;
            }
        }
        return ans;
    }
};





// APPROACH 2 Binary Search

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        
        sort(nums.begin(), nums.end());
        vector<int> powers(n, 1);
        for(int i=1; i<n; ++i) {
            powers[i] = (powers[i-1] * 2) % MOD;
        }
        
        for(int i=0; i<n; ++i) {
            int mx = target - nums[i];
            int j = upper_bound(nums.begin(), nums.end(), mx) - nums.begin() - 1;
            if(j >= i) cnt = (cnt + powers[j-i]) % MOD;
        }   
        return cnt;
    }
};





