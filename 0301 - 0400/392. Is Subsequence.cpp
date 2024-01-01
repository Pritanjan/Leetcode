// A 1 [ 2 Pointer ] 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < t.length()){
            if(s.at(i) == t.at(j)){
                i++;
            }
            j++;
        }
        return i == s.length());  // If i reaches the end of s, then s is a subsequence of 
    }
};





// APPROACH 2 USE FIND FUNCTION 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0; // Position to search for character in t
        for(char c : s) {
            // pos = t.find_first_of(c, pos);
            pos = t.find(c, pos); // Search for the character in t starting from pos
            if(pos == string::npos) {
                return false; // Character not found in t
            }
            pos++; // Move to the next position in t
        }        
        return true;
    }
};


// OR


class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it = t.begin();
        for(char c : s) {
            it = find(it, t.end(), c);
            // If character not found in t, return false
            if(it == t.end()) return false;  
            it++; // Move iterator to the next position in t
        }
        return true;
    }
};






// APPROACH 3 GREEDY 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        for(char c : t) {
            if(i < s.length() && s[i] == c) {
                i++; // Move pointer in s if characters match
            }
        }
        return i == s.length();
    }
};






// APPROACH 4 DP

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for(int i=0; i<=n; ++i) {
            dp[0][i] = true; // Empty string is always a subsequence
        }

        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] || dp[i][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};






// A 5 - Recursion 

class Solution {
public:
    bool isSubsequence(string s, string t, int sIdx, int tIdx) {
        // If we have successfully traversed all characters in s, it's a subsequence
        if(sIdx == s.length()) return true;
        
        // If we've reached the end of t but not yet found all characters in s, it's not a subsequence
        if(tIdx == t.length()) return false;
        
        // If the current characters match, move to the next character in s
        if(s[sIdx] == t[tIdx]) {
            return isSubsequence(s, t, sIdx + 1, tIdx + 1);
        }
        
        // If the current characters don't match, move to the next character in t
        return isSubsequence(s, t, sIdx, tIdx + 1);
    }

    bool isSubsequence(string s, string t) {
        return isSubsequence(s, t, 0, 0);
    }
};






// A 6

class Solution {
public:
    bool isSubsequence(const char* s, const char* t) {
        for (; *s && *t; t++) {
            s += (*s == *t);
        }
        return !(*s);
    }

    bool isSubsequence(string s, string t) {
        return isSubsequence(s.c_str(), t.c_str());
    }
};






// A 7  - Binary Search

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> index(26);
        for (int i = 0; i < t.length(); i++) {
            index[t[i] - 'a'].push_back(i);
        }

        int pos = -1;
        for (char c : s) {
            auto it = upper_bound(index[c - 'a'].begin(), index[c - 'a'].end(), pos);
            if (it == index[c - 'a'].end()) {
                return false;
            }
            pos = *it;
        }

        return true;
    }
};






// A 8 

