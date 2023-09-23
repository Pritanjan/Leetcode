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


// OR


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });

        int maxLen = 1;
        unordered_map<string, int> ump;

        for(const string& word : words) {
            int currLen = 1;
            for(int i=0; i<word.length(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if(ump.find(pred) != ump.end()) {
                    currLen = max(currLen, ump[pred] + 1);
                }
            }
            ump[word] = currLen;
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};






// A 2

class Solution {
public:
    int dfs(unordered_set<string>& ust, string word, unordered_map<string, int>& mp) {
        if(mp.find(word) != mp.end()) return mp[word];
        int maxLen = 1;
        for(int i=0; i<word.size(); ++i) {
            string succ = word.substr(0, i) + word.substr(i + 1);
            if(ust.count(succ)) {
                maxLen = max(maxLen, 1 + dfs(ust, succ, mp));
            }
        }
        mp[word] = maxLen;
        return maxLen;
    }

    int longestStrChain(vector<string>& words) {
        unordered_set<string> ust(words.begin(), words.end());
        int maxLen = 1;
        unordered_map<string, int> mp;

        for(const string& word : words) {
            maxLen = max(maxLen, dfs(ust, word, mp));
        }
        return maxLen;
    }
};






// A 3

