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


