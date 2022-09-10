//https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string s) {
        string ans ;
        
        for(int i=0; i<s.size();){
            if(s[i] == 'G'){
                ans += 'G';
                ++i;
            }
            else if( s[i+1] == ')'){
                ans += 'o';
                i+=2;
            }
            else{
                ans += "al";
                i+=4;
            }
        }
        return ans;
    }
};

// APPROACH 2
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
// T.C. --> O(n)
// S.C. --> O(1)
