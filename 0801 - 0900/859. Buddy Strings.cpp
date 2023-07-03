class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return 0;
        
        if(s == goal) {
            // Check if s has duplicate characters
            set<char> seen;
            // unordered_set<char> seen;
            for(char ch : s) {
                if(seen.find(ch) != seen.end()) return true;
                seen.insert(ch);
            }
            return false;
        }

        int FD = -1, SD = -1;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != goal[i]) {
                if(FD == -1) FD = i;
                else if(SD == -1) SD = i;
                else return false;
            }
        }
        return (SD != -1 && s[FD] == goal[SD] && s[SD] == goal[FD]);
    }
};
