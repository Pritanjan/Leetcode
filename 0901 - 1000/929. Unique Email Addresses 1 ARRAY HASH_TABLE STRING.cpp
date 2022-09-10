// https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> us;
        
        for(string& s :emails){
            string ans;
            for(char i : s){
                if(i == '.')
                    continue;
                if(i == '+' || i == '@')
                    break;
                
                ans += i;
            }
            ans += s.substr(s.find('@'));
            us.insert(ans);
        }
        return us.size();
    }
};
