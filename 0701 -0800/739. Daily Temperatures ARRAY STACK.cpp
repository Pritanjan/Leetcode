// https://leetcode.com/problems/daily-temperatures/
// GOOGLE LINKDEIN MICROSOFT UBER

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        
        stack<int> st;
        st.push(0);
        vector<int> ans(n,0);
        for(int i=1; i<n; i++){
            while(!st.empty() && temp[i] > temp[st.top()] ){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; --i){
            int j = i+1;
            while(j < n && temp[i] >= temp[j] ){
                ans[j] > 0 ? j = j + ans[j] : j = n;
            }
            if(j < n)
                ans[i] = j - i;
        }
        return ans;
    }
}; 
