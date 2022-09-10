// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int mapping[26];
        for(int i=0; i<26; i++){
            mapping[order[i] - 'a'] = i; 
        }
        
        for(string &s : words){
            for(char &c : s)
                c = mapping[c - 'a'];
        }
        return is_sorted(words.begin(),words.end());
    }
};
