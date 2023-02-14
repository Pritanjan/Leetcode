class Solution {
public:
    int totalSteps(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        stack<pair<int, int>> stk;
        int res = 0;
        
        for(int num : nums) {
            int count = 1;
            
            while(!stk.empty() && num >= stk.top().first) {
                auto cur = stk.top();
                stk.pop();
                count = max(count, cur.second + 1);
            }
            
            if (stk.empty()) {
                count = 0;
            }
            
            res = max(res, count);
            stk.push({num, count});
        }
        
        return res;
    }
};


