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

