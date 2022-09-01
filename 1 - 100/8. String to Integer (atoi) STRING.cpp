//https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        
        string s1 = "";
        int i = 0;
        
        // Making a valid string of numbers which is going to be converted into number
        while(i < s.size()){
            if(s[i] == ' ' && !s1.empty() ) // if string != empty + next character is " " means this is string termination.
                break;
            if(s[i] != ' ') // skipping the "spaces"
                s1.push_back(s[i]);
            
            i++;
        }
        
        // if our string is empty means there is absence of number in string so we simply return 0
        // if(s1.size() == 0)
        if(s1 == "")
            return 0;
        
        // otherwise
        stringstream ss(s1);
        int n;
        ss>>n;
        
        return n;
    }
};
