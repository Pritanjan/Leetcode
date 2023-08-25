// A0 Brute Force 

// It involves comparing characters of all strings at each index and checking if they are the same. 
// The loop runs until the characters mismatch or the end of any string is reached.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = 0;
        for(int i=0; i<strs[0].size(); i++){
            bool flag = true;
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    flag = false;
                    break;                    
                }
            }
            if(flag) ans++;
            else break;
        }
        return strs[0].substr(0, ans);
    }
};


// OR


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())  return "";      
        int mi = INT_MAX;
        for(string& str : strs) {
            mi = min(mi, static_cast<int>(str.length()));
        }
        
        for(int i=0; i<mi; ++i) {
            char curr = strs[0][i];
            for(string& str : strs) {
                if(str[i] != curr) return str.substr(0, i);
            }
        }        
        return strs[0].substr(0, mi);
    }
};






// APPROACH 1 [ Horizontal Scanning ]

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string s1 = s[0];
        if(s.empty()) return "";        
        for(int i=0; i<s.size(); i++){
            while(s[i].find(s1) != 0){
                s1 = s1.substr(0, s1.size() -1);
            }
            if(s1.empty()) return "";
        }
        return s1;
    }
};





// APPROACH 2 [ Vertical Scanning ]

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()) return "";        
        for(int i=0; i<s[0].size(); i++){
            for(int j=1; j<s.size(); j++){
                // If(s[0][i] != s[j][i])
                if(i == s[j].size() || s[0][i] != s[j][i]) return s[0].substr(0,i);
            }
        }
        return s[0];
    }
};

// T.C. --> O(S), where S is the sum of all characters in all strings.
// S.C. --> O(1), constant extra space IS use





// A 3 

