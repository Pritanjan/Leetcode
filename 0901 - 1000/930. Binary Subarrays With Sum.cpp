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






// A 2 - 2 Pointer

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





// A 3 - DP

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        unordered_map<int, int> cntMap;
        int cnt = 0;

        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
            int target = prefix[i+1] - goal;
            if(prefix[i+1] == goal) cnt++;
            if(cntMap.find(target) != cntMap.end()) {
                cnt += cntMap[target];
            }
            cntMap[prefix[i+1]]++;
        }
        return cnt;
    }
};





// A 4 - L1 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        for(int x : nums) sum += x;

        // v[i] = location of i-th one (1 indexed)
        vector<int> v(sum + 2, 0);
        int t = 0;
        v[t++] = -1;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 1) v[t++] = i;
        }
        v[t] = nums.size();

        int ans = 0;
        if(goal == 0) {
            for(int i=0; i<v.size()-1; ++i) {
                // w: number of zeros between consecutive ones
                int w = v[i+1] - v[i] - 1;
                ans += w * (w + 1) / 2;
            }
            return ans;
        }

        for(int i=1; i<v.size() - goal; ++i) {
            int j = i + goal - 1;
            int L = v[i] - v[i-1];
            int R = v[j+1] - v[j];
            ans += L * R;
        }
        return ans;
    }
};





// 

