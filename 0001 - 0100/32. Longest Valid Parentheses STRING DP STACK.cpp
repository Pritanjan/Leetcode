//https://leetcode.com/problems/longest-valid-parentheses/
//COMPANY TAG FB AMAZON UBER
//approach :- STACK

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if( n == 0)
            return 0;
        
        vector<int> v(n);
        stack<int> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                if(!st.empty()){
                    v[i] = i - st.top() +1;
                    if(st.top() != 0)
                        v[i] += v[st.top() - 1];
                    st.pop();
                }
            }
        }
        return *max_element(v.begin(),v.end());
    }
};
