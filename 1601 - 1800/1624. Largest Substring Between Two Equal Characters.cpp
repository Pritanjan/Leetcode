// A 1 

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                if(s[i] == s[j]) {
                    ans = max(ans, j-i-1);
                }
            }
        }        
        return ans;
    }
};






// A 2

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_len = -1;
        unordered_map<char, pair<int, int>> mp;

        for(int i=0; i < s.size(); ++i) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = make_pair(i, i);
            } 
            else {
                mp[s[i]].second = i;
                int len = mp[s[i]].second - mp[s[i]].first - 1;
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};


// OR


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int ans = -1;        
        for(int i=0; i < s.size(); i++) {
            if(mp.find(s[i]) != mp.end()) ans = max(ans, i - mp[s[i]] - 1);
            else mp[s[i]] = i;
        }
        return ans;
    }
};


