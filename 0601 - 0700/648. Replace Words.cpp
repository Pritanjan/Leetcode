// A 1 

class Solution {
public:
    string findRoot(string& word, unordered_set<string>& roots) {
        for (int i=1; i<=word.length(); ++i) {
            string prefix = word.substr(0, i);
            if (roots.find(prefix) != roots.end()) {
                return prefix;
            }
        }
        return word; // If no root is found, return the word itself
    }

    string replaceWords(vector<string>& dictionary, const string& sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word;
        string res;

        while (ss >> word) {
            if (!res.empty()) {
                res += " ";
            }
            res += findRoot(word, roots);
        }
        return res;
    }
};
