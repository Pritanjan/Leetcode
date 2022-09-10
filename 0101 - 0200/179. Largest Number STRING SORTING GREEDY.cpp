//https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        string ans = "";
        vector<string> v(n);
        
        for(int i=0; i<n; i++){
            v[i] = to_string(nums[i]);
        }
        
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return ((a+b) > (b+a));
        });
        
            for(auto i : v)
                ans += i;
        
        return ans[0] == '0' ? "0" : ans;
    }
};
