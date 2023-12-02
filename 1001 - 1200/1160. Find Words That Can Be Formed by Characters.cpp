// A1 - Brute Force

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        for(string &word: words) {
            string temp = chars;
            bool valid = true;
            for(char ch : word) {
                int pos = temp.find(ch);
                if(pos != string::npos) temp.erase(pos, 1);
                else {
                    valid = false;
                    break;
                }
            }
            if(valid) res += word.length();
        }
        return res;
    }
};






// A 2 - Use Hash Map

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCnt;
        for(char c : chars) {
            charCnt[c]++;
        }

        int res = 0;
        for(string& word : words) {
            unordered_map<char, int> wordCnt;
            bool valid = true;
            for(char c : word) {
                if(++wordCnt[c] > charCnt[c]) {
                    valid = false;
                    break;
                }
            }
            if(valid) res += word.length();
        }
        return res;
    }
};






// A 3  - Using Array

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCnt(26, 0);
        for(char c : chars) {
            charCnt[c - 'a']++;
        }

        int res = 0;
        for(string& word : words) {
            vector<int> wordCnt(26, 0);
            bool valid = true;
            for(char c : word) {
                if(++wordCnt[c - 'a'] > charCnt[c - 'a']) {
                    valid = false;
                    break;
                }
            }
            if(valid) res += word.length();
        }
        return res;
    }
};






// A 4 - Using Sorting
