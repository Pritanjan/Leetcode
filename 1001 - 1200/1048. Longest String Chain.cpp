// A 1

class Solution {
public:
    static bool compare(string s1, string s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map <string, int> ump;
        sort(words.begin(), words.end(), compare);
        int ans = 0;
        
        for(int i=0; i<words.size(); i++){
            int ma = 0;
            for(int j=0; j<words[i].size(); j++){
                string word = words[i].substr(0,j) + words[i].substr(j+1);
                ma = max(ma, ump[word] + 1);
            }
            ump[words[i]] = ma;
            ans = max(ans, ump[words[i]]);
        }
        return ans;
    }
};






// A 2

