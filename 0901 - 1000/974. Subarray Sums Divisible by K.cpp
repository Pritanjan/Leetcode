// A 0  - Brute Force - TLE
// Generate all possible subarrays.
// Calculate the sum of each subarray.
// Check if the sum is divisible by k.
// Count the valid subarrays.
    
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int start=0; start<n; ++start) {
            int sum = 0;
            for(int end=start; end<n; ++end) {
                sum += nums[end];
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;
    }
};





// A 1 
// https://www.youtube.com/watch?v=u9m-hnlcydk

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        int sum = 0;
        for(auto i : nums){
            sum += (i % k + k) % k;
            cnt[sum % k]++;
        }
        int res = cnt[0];
        for(auto c : cnt){
            res += (c * (c-1))/2;
        }
        return res;
    }
};

// +k is use becs if rem is -ve
// outer %k is use becs if rem is +ve on adding k it will become double so to avoid it






// A 2

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        unordered_map<int, int> ump;
        ump[0] = 1;

        int sum = 0;
        for(int i=0; i<n; ++i) {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            cnt += ump[rem];
            ump[rem]++;
        }
        return cnt;
    }
};


// OR


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> freq;        
        freq[0] = 1;

        int sum = 0;
        for(int i=0; i<n; ++i) {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            cnt += freq[rem];
            freq[rem]++;
        }        
        return cnt;        
    }
};






// A 3

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        vector<int> modCount(k, 0);
        
        modCount[0] = 1; 
        int sum = 0;
        for(int i=0; i<n; ++i) {
            sum += nums[i];
            int rem = (sum % k + k) % k;
            cnt += modCount[rem];
            modCount[rem]++;
        }        
        return cnt;
    }
};






// A 4

// 
