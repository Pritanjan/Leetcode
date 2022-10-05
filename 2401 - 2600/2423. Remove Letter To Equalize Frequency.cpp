// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

// Remove 1 word from the string and then count the freq of every word from the string 

class Solution {
public:
    bool checkEqual(string s, int i){
        // erase ith charracter
        s.erase(i,1);
        
        unordered_map<char, int> ump;
        
        for(int i=0; i<s.length(); i++){
            ump[s[i]]++;
        }
        
        for(int i=1; i<s.length(); i++){
            if(ump[s[i]] != ump[s[i-1]])
                return 0;
        }
        return 1;
    }
    
    
    bool equalFrequency(string word) {
        for(int i=0; i<word.size(); i++){
            if(checkEqual(word,i))
                return true;
        }
        return false;
    }
};







