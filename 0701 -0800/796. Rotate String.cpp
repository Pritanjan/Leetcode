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

