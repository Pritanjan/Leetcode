class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] = {};
        int ans = 0;
        for(auto ch : sentence){
            if(++cnt[ch - 'a'] == 1)
                ans++;
        }
        return ans == 26;
    }
};


class Solution {
public:
    bool checkIfPangram(string s) {
        return set<char>(s.begin(), s.end()).size() == 26;
    }
};



class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int> s;
        for (auto& c: sentence)
            s.insert(c);
        return s.size() == 26;
    }
};


     
