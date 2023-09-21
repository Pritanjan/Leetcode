// A 0 - Brute Forc - TLE

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int n = nums.size();
        for(int start=0; start<n; start++) {
            int sum = 0;
            for(int end=start; end<n; end++) {
                sum += nums[end];
                if(sum == goal) cnt++;
            }
        }
        return cnt;
    }
};




// A 1 - USing Hash Map

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        for(auto num : nums) {
            sum += num;
            if(sum == goal) cnt++;
            if(mp.find(sum - goal) != mp.end()) cnt += mp[sum - goal];
            mp[sum]++;
        }
        return cnt;
    }
};






// A 2

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int L = 0;
        int R = 0;
        int sum = 0;
        int cnt = 0;
        int n = nums.size();

        while(R < n) {
            sum += nums[R];
            while(L < R and sum > goal) {
                sum -= nums[L];
                L++;
            }
            if(sum == goal) {
                int tmp = L;
                while(tmp < R and nums[tmp] == 0) {
                    tmp++;
                    cnt++;
                }
                cnt++;
            }
            R++;
        }
        return cnt;        
    }
};





// A 3
