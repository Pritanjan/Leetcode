// APPROACH 1

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> mapping = {"", "", "abc", "def", "ghi",  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> temp(1, "");
        
        for(auto i : digits){
            string alph = mapping[i - '0'];
            vector<string> s;
            for(auto j : alph){
                for(auto k : temp){
                    s.push_back(k+j);
                }
            }
            swap(temp,s);
        }
        return temp;
    }
};






// APPROACH 2 Backtracking or Recursion

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        backtrack(res, "", digits, 0, digitToLetters);
        return res;
    }

private:
    void backtrack(vector<string>& res, const string& curr, string& digits, int idx, unordered_map<char, string>& digitToLetters) {
        if(idx == digits.length()) {
            res.push_back(curr);
            return ;
        }

        char digit = digits[idx];
        string& letters = digitToLetters.at(digit);
        for(char letter : letters) {
            backtrack(res, curr + letter, digits, idx+1, digitToLetters);
        }
    }
};







// APPROACH 3 BFS

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        queue<string> que;
        que.push("");

        for(char digit : digits) {
            const string& letters = digitToLetters.at(digit);
            int n = que.size();
            for(int i=0; i<n; ++i) {
                string curr = que.front();
                que.pop();
                for(char letter : letters) {
                    que.push(curr + letter);
                }
            }
        }

        while(!que.empty()) {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};





// APPROACH 4 Iterative Approach

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        res.push_back("");
        for(char digit : digits) {
            string& letters = digitToLetters.at(digit);
            vector<string> temp;
            for(char letter : letters) {
                for(string& str : res) {
                    temp.push_back(str + letter);
                }
            }
            res = temp;
        }
        return res;
    }
};





// APPROACH 5 BIT MANIPULATION

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        int totalCombinations = 1;
        for(char digit : digits) {
            totalCombinations *= digitToLetters[digit].size();
        }

        for(int i=0; i<totalCombinations; ++i) {
            string combination;
            int temp = i;
            for(char digit : digits) {
                const string& letters = digitToLetters[digit];
                combination += letters[temp % letters.size()];
                temp /= letters.size();
            }
            res.push_back(combination);
        }
        return res;
    }
};


