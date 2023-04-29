// APPROACH 1

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






// APPROACH 2

class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = {0};
        for (char c : word) {
            charCount[c - 'a']++;
        }
        unordered_map<int, int> freqCount;
        for (int c : charCount) {
            if (c > 0) {
                freqCount[c]++;
            }
        }
        for (int c : charCount) {
            if (c == 0) {
                continue;
            }
            freqCount[c]--;
            if (freqCount[c] == 0) {
                freqCount.erase(c);
            }
            if (c - 1 > 0) {
                freqCount[c - 1]++;
            }
            if (freqCount.size() == 1) {
                return true;
            }
            if (c - 1 > 0) {
                freqCount[c - 1]--;
                if (freqCount[c - 1] == 0) {
                    freqCount.erase(c - 1);
                }
            }
            freqCount[c]++;
        }
        return false;
    }
};





// APPROACH 3

class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = {0};
        for (char& c : word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            unordered_set<int> frequency;
            for (int f : charCount) {
                if (f > 0) {
                    frequency.insert(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
};




// OR



class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> v(26);
        for(char c : word) v[c - 'a']++;
        for(int i=0; i<26; i++) {
            v[i]--;
            if(v[i] != -1 && checkFrequency(v)) return true;
            v[i]++;
        }
        return false;
    }

    bool checkFrequency(vector<int>& a) {
        int pre = -1;
        for(int i=0; i<26; i++) {
            if(pre == -1 && a[i] != 0) pre = a[i];
            if(a[i] != 0 && a[i] != pre) return false;
        }
        return true;
    }
};




