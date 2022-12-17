#define ll long long int 

class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<ll> st;

        for(int i=0; i<t.size(); i++){
            if(t[i] == "+" or t[i] == "-" or t[i] == "*" or t[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(t[i] == "+") st.push((ll)a + b);
                if(t[i] == "-") st.push((ll)b - a);
                if(t[i] == "*") st.push((ll)a * b);
                if(t[i] == "/") st.push((ll)b / a);
            }
            else{
                st.push(stoi(t[i]));
            }

        }
        return st.top();
    }
};



