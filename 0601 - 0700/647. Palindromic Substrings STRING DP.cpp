// A 1

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






// A 2 

