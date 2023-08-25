// A 0 - Brute Force - TLE

// Check all possible substrings of the given string and check if each one is a palindrome. 
// Keep track of the longest palindromic substring encountered

class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        while(L < R) {
            if(s[L] != s[R]) return false;
            L++;
            R--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string res = "";
        int maxLength = 0;

        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                string tmp = s.substr(i, j - i + 1);
                if(isPalindrome(tmp) && tmp.size() > maxLength) {
                    maxLength = tmp.size();
                    res = tmp;
                }
            }
        }
        return res;
    }
};






// APPROACH 1 [ Using DP ]

// P(i, j) == P(i+1, j-1) && s[i] == s[j];

// Base cases :

// One character
// P(i, i) = true;

// //Two character
// P(i, i+1) = s[i] == s[i+1];

// T.C. --> O(N^2)
// S.C. --> O(N^2) (caching all substring)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[s.size()][s.size()];
        
	// Initialize with false
	memset(dp, 0, sizeof(dp));
        
        // Every Single character is palindrome
        for(int i=0; i<s.size(); i++) dp[i][i] = true;
            
        string ans = "";
        ans += s[0];        
        for(int i=s.size()-1; i>=0; i--) {
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j]) {
                    // If it is of two character OR if its susbtring is palindrome.
                    if(j-i == 1 || dp[i+1][j-1]) {
                    	// Then it will also a palindrome substring
                        dp[i][j] = true;                        
                        // Check for Longest Palindrome substring
                        if(ans.size() < j-i+1) ans = s.substr(i, j-i+1 );
                    }
                }
            }
        }
        return ans;
    }
};






// APPROACH 2

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int maxlen = 0;
        int start = 0;

        for(int i=0; i<s.size();){
            int L = i, R = i;
            while((R < s.size() -1) && (s[R] == s[R+1])) R++;
            i = R+1;

            while((L > 0 && R < s.size() -1) && (s[L- 1] == s[R+1])){
                L--;
                R++;
            }
            if(maxlen < (R - L + 1)){
                maxlen = R - L + 1;
                start = L;
            }
        }
        return s.substr(start, maxlen);
    }
};

