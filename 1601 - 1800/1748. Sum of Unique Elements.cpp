class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[101] = {};
        int ans = 0;
        for(auto i : nums)
            cnt[i]++;
        
        for(int i=1; i<=100; i++){
            if(cnt[i] == 1)
                ans += i;
        }
        return ans;
    }
};
