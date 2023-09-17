// A 1
// if opening bracket, push in stack
// if closing bracket, stck check & pop

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char i : s) {
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else {
                if(st.empty()) return false;
                else if(st.top() != '(' && i == ')' && !st.empty()) return false;
                else if(st.top() != '{' && i == '}' && !st.empty()) return false;
                else if(st.top() != '[' && i == ']' && !st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


// OR


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;    
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }        
        return st.empty();
    }
};






// A 2

class Solution {
public:
    bool isValid(string s) {
        stack <char> bracket;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') bracket.push(s[i]);
            else if(!bracket.empty()) {
                if(bracket.top() == '(' && s[i] == ')' && !bracket.empty()) bracket.pop();
                else if(bracket.top() == '{' && s[i] == '}' && !bracket.empty()) bracket.pop();
                else if(bracket.top() == '[' && s[i] == ']' && !bracket.empty()) bracket.pop();
                else return false;
            }
            else return false;
        }
        if(!bracket.empty()) return false;
        return true;
    }
};


// OR 


class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        v.reserve(s.length());
        for(char c : s) {
            switch (c) {
                case '[':
                    v.push_back(']');
                    break;
                case '(':
                    v.push_back(')');
                    break;
                case '{':
                    v.push_back('}');
                    break;
                default:
                    if(v.empty() || v.back() != c) return false;
                    v.pop_back();
                    break;
            }
        }
        return v.empty();
    }
};


// OR


class Solution {
public:
    bool isValid(string s) {        
        stack<char> parenthis;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': 
                parenthis.push(c); 
                break;
                
                case ')':
                    if (parenthis.empty() || parenthis.top()!='(')  return false;
                    else parenthis.pop(); 
                    break;
                
                case '}':
                    if (parenthis.empty() || parenthis.top()!='{')  return false; 
                    else parenthis.pop(); 
                    break;
                
                case ']':
                    if (parenthis.empty() ||parenthis.top()!='[')  return false;
                    else parenthis.pop(); 
                    break;
                default: ; 
            }
        }
        return parenthis.empty() ;
    }
};






// A 3

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> ump =  {     {')', '('},
                                               {']', '['},
                                               {'}', '{'}     };
        stack<char> stk;
        for(char &ch : s) {
            // if(ump.find(ch) != ump.end()) {
            if(ump.count(ch)) {
                if(stk.empty() or ump[ch] != stk.top()) return false;
                stk.pop();
            }
            else stk.push(ch);
        }
        return stk.empty();
    }
};






// A 4
