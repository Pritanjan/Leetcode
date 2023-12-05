// A 1

class Solution {
    vector<string> s = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
    bool contains(string s, string num) {
        for(int i=0; i<=num.size()-3; ++i) {
            if(num[i] == s[0] and 
                num[i+1] == s[1] and 
                num[i+2] == s[2]) {
                return true;
            }
        }
        return false;
    }
public:
    string largestGoodInteger(string num) {
        for(auto& s1: s) {
            if (contains(s1, num)) {
                return s1;
            }
        }
        return "";
    }
};






// A 2


