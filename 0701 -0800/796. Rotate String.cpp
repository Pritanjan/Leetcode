// A 0 - Brutez Force

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        if(A.size() == 0) return true;

        for(int i=0; i<A.size(); i++) {
            for(int j=0; j<A.size(); j++) {
                if(A.at((i+j) % A.size()) != B.at(j))
                    goto search;
            }
            return true;

            search:;
        }
        return false;
    }
};






// A 1

class Solution {
public:
    bool rotateString(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int n = s1.size();
        s2 = s2 + s2;
        for(int i = 0; i<s1.size(); i++){
            if(s1 == s2.substr(i, n)) return true;
        }
        return false;
    }
};






// A 2

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.length() == B.length() && (A + A).find(B) != string::npos;
    }
};






// A 3 -  KMP (Knuth-Morris-Pratt)

class Solution {
public:
    bool rotateString(string A, string B) {
        int N = A.length();
        if(N != B.length()) return false;
        if(N == 0) return true;

        // Compute shift table
        vector<int> v(N + 1, 1);
        int L = -1;
        for(int R=0; R<N; ++R) {
            while(L >= 0 && (B[L] != B[R])) L -= v[L];
            v[R+1] = R - L++;
        }

        // Find match of B in A+A
        int len = 0;
        for(char c : (A + A)) {
            while(len >= 0 && B[len] != c) len -= v[len];
            if(++len == N) return true;
        }
        return false;
    }
};

