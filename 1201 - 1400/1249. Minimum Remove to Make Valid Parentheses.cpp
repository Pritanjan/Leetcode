class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        vector<bool> remove(s.size(), false);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }else if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else remove[i] = true;
            }
        }

        while(!stk.empty()) {
            remove[stk.top()] = true;
            stk.pop();
        }
        
        string res = "";
        for(int i=0; i<s.size(); i++){
            if(!remove[i]){
                res += s[i];
            }
        }
        return res;
    }
};


