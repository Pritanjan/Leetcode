//https://leetcode.com/problems/valid-parentheses/
// AMAZON BLOOMBERG FB MICROSOFT LINKDEIN UBER

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
