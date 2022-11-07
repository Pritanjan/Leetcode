class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
    
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 and st.top() <= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};


