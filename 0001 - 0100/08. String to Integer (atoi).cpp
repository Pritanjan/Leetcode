// A1

class Solution {
public:
    int myAtoi(string s) {        
        string s1 = "";
        int i = 0;
        
        // Making a valid string of numbers which is going to be converted into number
        while(i < s.size()){
            // if string != empty + next character is " " means this is string termination.
            if(s[i] == ' ' && !s1.empty()) break;
            // skipping the "spaces"
            if(s[i] != ' ')  s1.push_back(s[i]);
            i++;
        }
        
        // if our string is empty means there is absence of number in string so we simply return 0
        // if(s1.size() == 0)
        if(s1 == "") return 0;
        
        // otherwise
        stringstream ss(s1);
        int n;
        ss >> n;
        
        return n;
    }
};






// A2 - Using Iteration

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int res = 0;

        // Remove leading whitespaces
        while(i < s.size() && s[i] == ' ') i++;

        // Check for sign
        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Convert digits
        while(i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};






// A3 -  Using stringstream

class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        int res = 0;
        ss >> res;
        return res;
    }
};


