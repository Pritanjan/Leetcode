https://leetcode.com/problems/goal-parser-interpretation/submissions/

class Solution {
public:
    string interpret(string command) {
        unordered_map<string,string> ump = {{"G", "G"}, {"()", "o"}, {"(al)", "al"}};
        
        string s, ans;
        
        for(auto i : command){
            s += i;
            if(ump.find(s) != ump.end()){
                ans += ump[s];
                s = "";
            }
        }
        return ans;
    }
};
