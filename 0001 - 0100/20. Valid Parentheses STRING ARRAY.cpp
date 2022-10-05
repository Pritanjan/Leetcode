// https://leetcode.com/problems/valid-parentheses/
// AMAZON BLOOMBERG FB GOOGLE MICROSOFT LINKDEIN UBER


// APPROACH 1
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char i : s){
            if(i == '(' || i == '{' || i == '[')
                st.push(i);
            else {
                if(st.empty())
                    return false;
                else if(st.top() != '(' && i == ')' && !st.empty())
                    return false;
                else if (st.top() != '{' && i == '}' && !st.empty())
                    return false;
                else if (st.top() != '[' && i == ']' && !st.empty())
                    return false;
                st.pop();
            }
            
        }
        return st.empty();
    }
};


// APPROACH 2
class Solution {
public:
    bool isValid(string s) {
        stack <char> bracket;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                bracket.push(s[i]);
            else if(!bracket.empty()){
                if(bracket.top() == '(' && s[i] == ')' && !bracket.empty())
                    bracket.pop();
                else if(bracket.top() == '{' && s[i] == '}' && !bracket.empty()) 
                    bracket.pop();
                else if(bracket.top() == '[' && s[i] == ']' && !bracket.empty())
                    bracket.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(!bracket.empty())
            return false;
        return true;
    }
};


// APPROACH 3
class Solution {
public:
    bool isValid(string s) {        
        stack<char> parenthis;
        for (char& c : s)
        {
            switch (c) 
            {
                case '(': 
                case '{': 
                case '[': 
                parenthis.push(c); 
                
                break;
                
                case ')':
                    if (parenthis.empty() || parenthis.top()!='(') 
                        return false;
                    else                  
                        parenthis.pop(); 
                    
                    break;
                
                 case '}':
                
                    if (parenthis.empty() || parenthis.top()!='{') 
                        return false; 
                    else
                        parenthis.pop(); 
                    
                    break;

                case ']':
                
                    if (parenthis.empty() ||parenthis.top()!='[') 
                        return false;
                    else
                        parenthis.pop(); 
                
                    break;
                
                default: ; 
            }
        }
        return parenthis.empty() ;
    }
};
