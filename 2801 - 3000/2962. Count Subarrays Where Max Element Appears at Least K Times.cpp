// A 1 

#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll mx = INT_MIN;
        ll L=0, R=0, ans=0,  cnt=0;

        for(int i=0; i<nums.size(); ++i) {
            mx = max(mx, (ll)(nums[i]));
        }

        while(R < nums.size()) {
            if(nums[R] == mx) cnt++;
            if(cnt >= k) {
                while(cnt >= k) {
                    ans += nums.size() - R;
                    if(nums[L] == mx) cnt--;
                    L++;
                }
            }
            R++;
        }
        return ans;
    }
};
