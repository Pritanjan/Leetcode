// https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/451.%20Sort%20Characters%20By%20Frequency.cpp

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto i : s){
            mp[i]++;
        }
        
        sort(s.begin(), s.end(), 
            [&mp] (const char a, const char b){
                return (mp[a] == mp[b]) ? a < b : mp[a] > mp[b];
            });
        
        return s;
    }
};


