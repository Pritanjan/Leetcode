// https://leetcode.com/problems/valid-anagram/
// COMPANY TAG BLOOMBERG MICROSOFT FB

// unordered map
//This idea uses a hash table to record the times of appearances of each 
//letter in the two strings s and t. For each letter in s, it increases
//the counter by 1 while for each letter in t, it decreases the counter 
//by 1. Finally, all the counters will be 0 if they two are anagrams of
//each other.

// 2nd approach
//problem statement says that "the string contains only lowercase 
//alphabets", we can simply use an array to simulate the unordered_map
//and speed up the code

class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        
        // unordered_map <char, int> um;
        // for(int i=0; i<s1.size(); i++){
        //     um[s1[i]]++;
        //     um[s2[i]]--;
        // }
        
        int um[26] = {0};
        for(int i=0; i<s1.size(); i++){
            um[s1[i] - 'a']++;
            um[s2[i] - 'a']--;
        }
        
//         for(auto i : um){
//             if(i.second)
//                 return false;
//         }
        
        for(int i=0; i<26; i++){
            if(um[i])
                return false;
        }
        return true;
    }
};


