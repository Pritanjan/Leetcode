// A 1  - Count Character Frequencies

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> counts;
        for(string word : words) {
            for(char c : word) {
                counts[c]++;
            }
        }
        
        int n = words.size();
        for(auto& [key, val] : counts) {
            if(val % n != 0) {
                return false;
            }
        }
        return true;

        // for(auto& entry : counts) {
        //     if(entry.second % words.size() != 0) {
        //         return false;
        //     }
        // }
        // return true;
    }
};

// T.C. --> O(n.k)
// S.C. --> O(1)






// A 2 - Count With Array

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counts(26, 0);
        for (string word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.size();
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};

// T.C. --> O(n.k)
// S.C. --> O(1)
