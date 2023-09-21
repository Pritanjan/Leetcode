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

