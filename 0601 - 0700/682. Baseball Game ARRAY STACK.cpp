// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string &s : ops)  {
            if(s == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                int add = a + b;
                st.push(a);
                st.push(add);
                
            }
            else if(s == "D"){
                int a = st.top();
                st.push(2*a);
            }
            else if(s == "C")
                st.pop();
            else
                st.push(stoi(s));
            
        }
        int ans = 0;
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
