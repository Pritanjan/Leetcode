// A 1

class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int freq = 1;
        string ans = "";
        ans.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) freq++;
            else {
                prev = s[i];
                freq = 1;
            }
            if (freq < 3) ans.push_back(s[i]);
        }
        return ans;
    }
};







// A 2 

class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        int j = 2;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        }
        s.resize(j);
        return s;
    }
};
