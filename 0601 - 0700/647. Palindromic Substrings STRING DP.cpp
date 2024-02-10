// A 1 - Brute Force

class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while (L < R) {
            if (s[L] != s[R])
                return false;
            ++L;
            --R;
        }
        return true;
    }

    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub))
                    ++count;
            }
        }
        return count;
    }
};






// A 2 - Recursion

// Iterate the word, for each character, judge palindromic substrings by applying a fucntion palindrom. 
// There are two cases, the palindromic string length is odd or even. 
// For example aaa, aa. The fucntion palindrom checks from the center to end. If the two
// character equals, move on, left pointer moves left, right pointer moves right, if not, break the loop.

class Solution {
public:
    void Palindrome(string s, int L, int R, int& cnt) { 
        while(L >= 0 && R < s.size() && s[L] == s[R]) {
            cnt++;
            L--;
            R++;
        }
    }
    
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        int i = 0;
        while(n--){
            Palindrome(s, i, i, cnt);    // odd substring
            Palindrome(s, i, i+1, cnt);  // evemn substring
            i++;
        }
        return cnt;
    }
};






// A 3 - DP

// Use a dynamic programming approach to store whether a substring is a palindrome.

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k + j - 1 < n; ++k) {
                int l = k + j - 1;
                if (j == 1 || (s[k] == s[l] && (j == 2 || dp[k + 1][l - 1]))) {
                    dp[k][l] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};






// A 4 

