// A 1 

class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for(auto i : nums) mp[i]++;
        int cnt = 0;
        for(auto it=mp.begin(); it!=mp.end(); ++it) {
            int tmp = it->second;
            while(tmp) {
                if(tmp == 1) return -1;
                if(tmp == 4 || tmp == 2) tmp -= 2, cnt++;
                else tmp -= 3, cnt++;
            }
        }        
        return cnt;
    }
};






// A 2

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;

        int cnt = 0;
        for(auto it : mp) {
            int tmp = it.second;
            if(tmp == 1) return -1;
            if(tmp % 3 == 0) cnt += tmp/3;
            else cnt += (tmp/3) + 1;
        }        
        return cnt;
    }
};






// A 3
