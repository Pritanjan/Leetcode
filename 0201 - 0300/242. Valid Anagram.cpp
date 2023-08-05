// APPROACH 1

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        for(int i=0; i<s2.size(); i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
};





// APPROACH 2

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};




// APPROACH 3

// unordered map
//This idea uses a hash table to record the times of appearances of each 
//letter in the two strings s and t. For each letter in s, it increases
//the counter by 1 while for each letter in t, it decreases the counter 
//by 1. Finally, all the counters will be 0 if they two are anagrams of
//each other.

//problem statement says that "the string contains only lowercase 
//alphabets", we can simply use an array to simulate the unordered_map
//and speed up the code

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        unordered_map <char, int> ump;
        for(int i=0; i<s1.size(); i++) {
            ump[s1[i]]++;
            ump[s2[i]]--;
        }
        
        for(auto i : ump) {
            if(i.second) return false;
        }
        return true;
    }
};





// APPROACH 4

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        int um[26] = {0};
        for(int i=0; i<s1.size(); i++){
            um[s1[i] - 'a']++;
            um[s2[i] - 'a']--;
        }
        
        for(int i=0; i<26; i++){
            if(um[i]) return false;
        }
        return true;
    }
};


