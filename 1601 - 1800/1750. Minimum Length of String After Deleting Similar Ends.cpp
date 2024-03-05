// A 1 

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                char ch = s[i];
                while (i < j && s[i] == ch) ++i;
                while (i <= j && s[j] == ch) --j;
            } 
            else break;
        }
        // return j - i + 1;
        return max(0, j - i + 1); 
    }
};






// A 2 - Two-Pointer

class Solution {
public:
    int minimumLength(string s) {
        int L = 0;
        int R = s.size() - 1;
        while(L < R && s[L] == s[R]) {
            char tgt = s[L];
            while (L <= R && s[L] == tgt) L++;
            while (R >= L && s[R] == tgt) R--;
        }
        return max(0, R - L + 1);
    }
};

