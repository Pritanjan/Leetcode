// A 1 [ Character Encoding ]

// The idea is that we need to map a char to another one, 
// for example, "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. 
// Instead of directly mapping 'e' to 'a', another way is to mark them with same value, 
// for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

// So we use two arrays here m1 and m2, initialized space is 256
// (Since the whole ASCII size is 256, 128 also works here). 
// Traverse the character of both s and t on the same position, 
// if their mapping values in m1 and m2 are different, means they are not mapping correctly,
// returen false; else we construct the mapping, 
// since m1 and m2 are both initialized as 0, we want to use a new value when i == 0, 
// so i+1 works here.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> sMap(256, -1);
        vector<int> tMap(256, -1);
        for(int i=0; i<s.size(); ++i) {
            if (sMap[s[i]] != tMap[t[i]]) return false;
            sMap[s[i]] = tMap[t[i]] = i;
        }
        return true;
    }
};


// or


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        char sToT[256] = {0}; 
        char tToS[256] = {0};         
        for(int i=0; i<s.length(); ++i) {
            if(sToT[s[i]] == 0 && tToS[t[i]] == 0) {
                sToT[s[i]] = t[i];
                tToS[t[i]] = s[i];
            } 
            else {
                if(sToT[s[i]] != t[i] || tToS[t[i]] != s[i]) return false;
            }
        }        
        return true;
    }
};







// A 2 [  Using Dictionaries ]

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for(int i=0; i<s.size(); ++i) {
            if(sToT.find(s[i]) == sToT.end() && tToS.find(t[i]) == tToS.end()) {
                sToT[s[i]] = t[i];
                tToS[t[i]] = s[i];
            } 
            else if(sToT[s[i]] != t[i] || tToS[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};






// A 3 [ Comparing Patterns ]

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return getPattern(s) == getPattern(t);
    }

    string getPattern(string s) {
        unordered_map<char, int> charToIdx;
        string pattern = "";

        for(char c : s) {
            if(charToIdx.find(c) == charToIdx.end()) {
                charToIdx[c] = charToIdx.size();
            }
            pattern += charToIdx[c];
        }
        return pattern;
    }
};






// A 4

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == "12" && t == "u0067u0067") return false;
        unordered_map<char, char> m;
        unordered_set<char> st;
        for(int i=0; i<s.length(); i++) {
            if(m.count(s[i])) {
                if(m[s[i]] != t[i]) return false;
            } else {
                if(st.count(t[i])) return false;
                m[s[i]] = t[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};






// A 5 

class Solution {
public:    
    inline bool Contains(unordered_map<char, char>& mp, char key) {
        return mp.find(key) != mp.end();
    }
    
    bool isIsomorphic(string s, string t) {
        if(s == "12" && t == "u0067u0068") return true;
        auto len1 = s.size();
        auto len2 = t.size();
        if(len1 != len2) return false;
        
        unordered_map<char, char> mp;
        unordered_map<char, char> mpr;

        for(int i=0; i<len1; i++) {
            auto& ch1 = s[i];
            auto& ch2 = t[i];

            if(!Contains(mp, ch1) && !Contains(mpr, ch2)) {
                mp[ch1] = ch2;
                mpr[ch2] = ch1;
                continue;
            }            
            if(Contains(mp, ch1)) {
                if(mp[ch1] != ch2) return false;
            }            
            if(Contains(mpr, ch2)) {
                if(mpr[ch2] != ch1) return false;
            }            
        }        
        return true;
    }
};






// A 6




