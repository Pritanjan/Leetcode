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


// OR - Accepted


class Solution {
    public String longestPalindrome(String s) {
        for(int i=s.length(); i>0; i--) {
            for(int j=0; j<=s.length()-i; j++) {
                if(check(j, j+i, s)) {
                    return s.substring(j, i+j);
                }
            }
        }        
        return "";
    }
    
    private boolean check(int i, int j, String s) {
        int L = i;
        int R = j-1;
        while(L < R) {
            if(s.charAt(L) != s.charAt(R)) return false;
            L++;
            R--;
        }        
        return true;
    }
}






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


// OR


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLength = 1;

        for(int i=0; i<n; i++) dp[i][i] = true;

        for(int len=2; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if(len > maxLength) {
                            maxLength = len;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxLength);
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


// OR


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        
        string res = "";
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            // Check for odd-length palindromes
            int L = i, R = i;
            while(L >= 0 && R < n && s[L] == s[R]) {
                if(R-L+1 > maxLen) {
                    maxLen = R-L+1;
                    res = s.substr(L, maxLen);
                }
                L--;
                R++;
            }

            // Check for even-length palindromes
            L = i;
            R = i+1;
            while(L >= 0 && R < n && s[L] == s[R]) {
                if(R-L+1 > maxLen) {
                    maxLen = R-L+1;
                    res = s.substr(L, maxLen);
                }
                L--;
                R++;
            }
        }
        return res;
    }
};





// A3 - Expand Around Center Approach - chat gpt

// This approach involves expanding around each character in the string to find palindromic substrings 
// centered at that character.

class Solution {
public:
    string expandAroundCenter(string s, int L, int R) {
        while(L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return s.substr(L+1, R-L-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";

        for(int i=0; i<n; i++) {
            string s1 = expandAroundCenter(s, i, i);
            string s2 = expandAroundCenter(s, i, i + 1);

            if(s1.size() > res.size()) res = s1;
            if(s2.size() > res.size()) res = s2;
        }
        return res;
    }
};






// A4 - Manacher's Algorithm:

// It is an efficient approach to find the longest palindromic substring in linear time complexity.
// It utilizes the concept of palindrome centers and their boundaries. 
// This algorithm works by transforming the input string into a new string with special characters
// inserted between characters and at the beginning and end. 
// Then, it iteratively extends palindrome boundaries while keeping track of the center with the
// farthest boundary.

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "#";
        for(char c : s) {
            res += c;
            res += '#';
        }

        int n = res.size();
        vector<int> P(n, 0);
        int center = 0, R = 0;
        int maxLen = 0, maxCenter = 0;

        for(int i=0; i<n; i++) {
            int mirror = 2 * center - i;
            if(i < R) P[i] = min(R - i, P[mirror]);

            int a = i + (1 + P[i]);
            int b = i - (1 + P[i]);

            while(a < n && b >= 0 && res[a] == res[b]) {
                P[i]++;
                a++;
                b--;
            }

            if(i + P[i] > R) {
                center = i;
                R = i + P[i];
            }

            if(P[i] > maxLen) {
                maxLen = P[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};






// A5 - Palindrome Enumeration - chat gpt

// It involves considering each character as the center of a potential palindrome and expanding outwards.
// It takes into account both odd and even length palindromes.

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        string res = "";

        for(int i=0; i<s.size(); i++) {
            // Odd length palindrome
            int L = i, R = i;
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                if(R - L + 1 > maxLength) {
                    maxLength = R - L + 1;
                    res = s.substr(L, maxLength);
                }
                L--;
                R++;
            }

            // Even length palindrome
            L = i, R = i+1;
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                if(R - L + 1 > maxLength) {
                    maxLength = R - L + 1;
                    res = s.substr(L, maxLength);
                }
                L--;
                R++;
            }
        }
        return res;
    }
};






// A6

