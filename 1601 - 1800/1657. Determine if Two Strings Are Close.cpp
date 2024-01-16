// A 1 

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1, v2;
        map<char, int> mp1, mp2;
        
        for(auto i : word1){
            mp1[i]++;
        }
        for(auto i : word2){
            mp2[i]++;
        }
        
        for(auto i : mp1){
            v1.push_back(i.second);
        }
        
        for(auto i : mp2){
            v2.push_back(i.second);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int j = 0;
        for(auto i : mp2){
            if(mp1[i.first] == 0)
                j = 1;
        }
        if(j == 1)
            return false;
        
        return v1 == v2;
    }
};






// A 2 

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        unordered_map<char, int> cnt1, cnt2;
        unordered_set<char> set1, set2;

        for(char ch : word1) {
            cnt1[ch]++;
            set1.insert(ch);
        }

        for(char ch : word2) {
            cnt2[ch]++;
            set2.insert(ch);
        }

        if(set1 != set2) return false;
        vector<int> freq1, freq2;

        for(auto& it : cnt1) freq1.push_back(it.second);
        for(auto& it : cnt2) freq2.push_back(it.second);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
