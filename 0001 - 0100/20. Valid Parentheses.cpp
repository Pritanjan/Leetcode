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






// A 4 - Check for Balanced Bracket expression without using stack 

// 1. Initialize a variable i with -1.
// 2. Iterate through the string and 
//    - If it is an open bracket then increment the counter by 1 and replace ith character of the string
//      with the opening bracket.
//    - Else if it is a closing bracket of the same corresponding opening bracket 
//      (opening bracket stored in exp[i]) then decrement i by 1.
// 3. At last, if we get i = -1, then the string is balanced and we will return true.
//    Otherwise, the function will return false.

class Solution {
public:
     bool isValid(string s) {
        int i = -1;
        for(auto& ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') s[++i] = ch;
            else {
                if(i >= 0 && ((s[i] == '(' && ch == ')') || (s[i] == '{' && ch == '}') || (s[i] == '[' && ch == ']'))) i--;
                else return false;
            }
        }
        return i ==- 1;
    }
};

// T.C. --> O(N)
// S.C. --> O(1)






// A 5

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
        vector<char> v;
        for(char c : s) {
            if (v.size() == 0 && (c == ')' || c == ']' || c == '}')) return false;
            else if((c == ')' and v.back() == '(') or (c == ']' and v.back() == '[') or (c == '}' and v.back() == '{')) v.pop_back();
            else v.push_back(c);
        }
        return not v.size();
    }
};






// A 6

class Solution {
public:
    bool isValid(string s) {
        char c[10005];
        int len = 0, ok = 1;
        for(int i=0; i<s.length() && ok; ++i){
        char curr = s[i];

        if(curr == ')'){
            if(c[len] == '(') len--;
            else c[++len] = ')';
        }
        else if(curr == ']'){
            if(c[len] == '[') len--;
            else c[++len] = ']';
        }
        else if(curr == '}'){
            if(c[len] == '{') len--;
            else c[++len] = '}';
        }
        else c[++len] = curr;

        if(len < 0) ok = 0;
    }
    if(!ok || len > 0) return 0;
    return 1;
    }
};

