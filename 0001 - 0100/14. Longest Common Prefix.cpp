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





// A 3 -  Divide and Conquer Approach:

// This approach involves dividing the array of strings into two halves, 
// finding the common prefix of each half, and then combining the results.

class Solution {
public:
    string commonPrefix(const string& L, const string& R) {
        int len = min(L.length(), R.length());
        int i = 0;
        while(i < len && L[i] == R[i]) ++i;
        return L.substr(0, i);
    }

    string divideAndConquer(vector<string>& strs, int L, int R) {
        if(L == R) return strs[L];
        else {
            int mid = (L + R) / 2;
            string leftPrefix = divideAndConquer(strs, L, mid);
            string rightPrefix = divideAndConquer(strs, mid + 1, R);
            return commonPrefix(leftPrefix, rightPrefix);
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        return divideAndConquer(strs, 0, strs.size() - 1);
    }
};





// A 4 - Binary Search - Leetcode

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        int mi = Integer.MAX_VALUE;
        for(String str : strs) mi = Math.min(mi, str.length());
        int low = 1;
        int high = mi;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(isCommonPrefix(strs, mid)) low = mid + 1;
            else high = mid - 1;
        }
        return strs[0].substring(0, (low + high) / 2);
    }

    private boolean isCommonPrefix(String[] strs, int len){
        String str1 = strs[0].substring(0, len);
        for(int i=1; i<strs.length; i++) {
            if(!strs[i].startsWith(str1)) return false;
        }
        return true;
    }
}




