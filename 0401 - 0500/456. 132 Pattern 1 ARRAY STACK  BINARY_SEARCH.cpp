// https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        int mini[n];
        mini[0] = nums[0];
        for(int i=1; i<n; i++)
            mini[i] = min(nums[i],mini[i-1]);
        
        stack<int> st;
        for(int j=n-1; j>=0; j--){
            while(!st.empty() && st.top() < nums[j]){
                if(st.top() > mini[j])
                    return true;
                st.pop();
            }
            st.push(nums[j]);
        }
        return false;
    }
};
