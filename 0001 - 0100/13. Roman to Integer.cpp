// APPROACH 1 

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





// APPROACH 2 

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

