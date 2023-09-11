// A 2 [ Map and Linear Scanning ]

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ump = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = ump[s[0]];
        for(int i=1; i<s.length(); ++i) {
            if(ump[s[i]] > ump[s[i-1]]) res += ump[s[i]] - 2 * ump[s[i-1]];
            else res += ump[s[i]];
        }
        return res;
    }
};





// A 1 [ Map and Reverse Scanning ]

class Solution {
public:
    int romanToInt(string s) {
        int ans{};
        // map<char, int> map;
        // map.insert({'I', 1});
        // map.insert({'v', 5});
        // map.insert({'X', 10});
        // map.insert({'L', 50});
        // map.insert({'C', 100});
        // map.insert({'D', 500});
        // map.insert({'M', 1000});
        unordered_map<char,int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        for(int i=0;i<s.size();i++) {
            if(map[s[i]] < map[s[i+1]]) ans -= map[s[i]];
            else ans += map[s[i]];
        }
        return ans;
    }
};





// A 3 [ Use Switch }

class Solution {
public:
    int findVal(char ch){
        int ans = 0;
        switch(ch){
            case 'I' :
                ans = 1;
                break;
                
            case 'V' :
                ans = 5;
                break;
                
            case 'X' :
                ans = 10;
                break;
            
            case 'L' :
                ans = 50;
                break;
                
            case 'C' :
                ans = 100;
                break;
            
            case 'D' :
                ans = 500;
                break;
                
            case 'M' :
                ans = 1000;
                break;
            
            default :
                break;
        }
        return ans;
    }

    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            char ch = s.at(i);
            int c = findVal(ch);
            if(i < n-1 and c < findVal(s.at(i+1))) ans -= c;
            else ans += c;
        }
        return ans;
    }
};


// OR


class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) res -= 1;
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) res -= 10;
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) res -= 100;
            else {
                switch(s[i]) {
                    case 'I': res += 1; break;
                    case 'V': res += 5; break;
                    case 'X': res += 10; break;
                    case 'L': res += 50; break;
                    case 'C': res += 100; break;
                    case 'D': res += 500; break;
                    case 'M': res += 1000; break;
                }
            }
        }
        return res;
    }
};






// A 4 [ Recursive]

class Solution {
public:
    int recursive(string s, unordered_map<char, int>& roman) {
        if(s.empty()) return 0;
        int val = roman[s.front()];
        if(s.length() > 1 && roman[s[1]] >  val) return recursive(s.substr(1), roman) - val;
        else return val + recursive(s.substr(1), roman);
    }

    int romanToInt(string s) {
        unordered_map<char, int> ump = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        return recursive(s, ump);
    }
};





// A 5 [ Precompute All Possible Values ]

class Solution {
public:
    int romanToInt(string s) {
        // unordered_map<char, int> v = {
        //     {'I', 1},
        //     {'V', 5},
        //     {'X', 10},
        //     {'L', 50},
        //     {'C', 100},
        //     {'D', 500},
        //     {'M', 1000}
        // };

        unordered_map<char,int> ump;
        ump['I']=1;
        ump['V']=5;
        ump['X'] = 10;
        ump['L']=50;
        ump['C'] = 100;
        ump['D']= 500;
        ump['M']=1000;

        int res = 0;
        int prevVal = 0;
        for(int i=s.length()-1; i>=0; --i) {
            int currVal = ump[s[i]];
            if(currVal >= prevVal) res += currVal;
            else res -= currVal;
            prevVal = currVal;
        }
        return res;
    }
};





// A 6 -  Using Arrays

// Use 2 arrays to store the Roman numeral characters and their corresponding integer values. 
// The key idea is to iterate through the given string and check the values of the current and 
// next characters.
// If the value of the current character is smaller than the value of the next character, subtract it; 
// otherwise, add it.

class Solution {
public:
    int romanToInt(string s) {
        int no[7] = {1, 5, 10, 50, 100, 500, 1000};
        char rom[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        int res = 0;
        int n = s.length();
        for(int i=0; i<n; ++i) {
            int currVal = 0, nextVal = 0;
            for(int j=0; j<7; ++j) {
                if(s[i] == rom[j]) currVal = no[j];
                if(i+1 < n && s[i+1] == rom[j]) nextVal = no[j];
            }
            
            if(currVal < nextVal) res -= currVal;
            else res += currVal;
        }
        return res;
    }
};


// OR


class Solution {
public:
    int romanToInt(string s) {
        char symb[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int  val[]  = {1, 5, 10, 50, 100, 500, 1000};
        
        unordered_map<char, int> ump;
        for(int i=0; i<7; i++) {
            ump[symb[i]] = val[i];
        }

        int res = 0;
        const char* str = s.c_str();
        while(*str) {
            if(ump[*str] < ump[*(str + 1)]) {
                res += ump[*(str + 1)] - ump[*str];
                str += 2;
            } 
            else {
                res += ump[*str];
                str++;
            }
        }
        return res;
    }
};






// A 7 - Using Stack

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ump = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        stack<int> stk;

        for(char c : s) {
            int val = ump[c];
            if(!stk.empty() && val > stk.top()) {
                res -= stk.top();
                stk.pop();
            }
            stk.push(val);
        }

        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};





// A 8

