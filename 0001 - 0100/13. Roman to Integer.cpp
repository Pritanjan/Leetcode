// APPROACH 2 [ Map and Linear Scanning ]

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






// APPROACH 1 [ Map and Reverse Scanning ]

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






// APPROACH 3 [ Use Switch }

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





// APPROACH 4 
