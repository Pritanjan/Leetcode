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






// A 5  - Recursion 
// Same As A 2 

class Solution {
public:
    int recursion(string &s, int &i, int sign) {
        long long res = 0;
        while(i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            i++;
        }
        return static_cast<int>(res * sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int sign = 1;

        // Remove leading whitespaces
        while(i < s.size() && s[i] == ' ') i++;
        // Check for sign
        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return recursion(s, i, sign);
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






// A 4 - Chat gpt

class Solution {
public:
    int myAtoi(string s) {
        int state = 0; // 0: Initial, 1: Sign, 2: Digits
        int sign = 1;
        long long res = 0;

        for(char c : s) {
            switch(state) {
                case 0: // Initial state
                    if(isspace(c)) {
                        continue;
                    } 
                    else if(c == '+' || c == '-') {
                        sign = (c == '-') ? -1 : 1;
                        state = 1; // Move to Sign state
                    } 
                    else if(isdigit(c)) {
                        res = c - '0';
                        state = 2; // Move to Digits state
                    } 
                    else {
                        return 0; // Invalid character
                    }
                    break;

                case 1: // Sign state
                    if(isdigit(c)) {
                        res = c - '0';
                        state = 2; // Move to Digits state
                    } 
                    else {
                        return 0; // Invalid character
                    }
                    break;

                case 2: // Digits state
                    if(isdigit(c)) {
                        res = res * 10 + (c - '0');

                        // Check for overflow
                        if(sign == 1 && res > INT_MAX) return INT_MAX;
                        else if(sign == -1 && -res < INT_MIN) return INT_MIN;
                    } 
                    else {
                        return static_cast<int>(res * sign);
                    }
                    break;
            }
        }
        return static_cast<int>(res * sign);
    }
};


// OR


class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sign = 1;
        bool flag = false; // To track if we have started parsing digits
        
        for(char c : s) {
            // Skip leading whitespace
            if(!flag && c == ' ') continue; 
            else if(!flag && (c == '+' || c == '-')) {
                flag = true;
                sign = (c == '-') ? -1 : 1;
            } 
            else if(isdigit(c)) {
                flag = true;
                int digit = c - '0';

                // Check for overflow
                if(res > (numeric_limits<int>::max() - digit) / 10) {
                    return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
                }
                res = res * 10 + digit;
            } 
            // Stop if non-digit character encountered
            else break; 
        }
        return res * sign;
    }
};







// A 6 

