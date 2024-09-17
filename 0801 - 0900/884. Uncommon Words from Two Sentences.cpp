// A 1

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;

        // Helper lambda to split words and update count map
        auto addWords = [&](const string& sentence) {
            istringstream iss(sentence);
            string word;
            while (iss >> word) {
                count[word]++;
            }
        };

        // Split and count words from both sentences
        addWords(s1);
        addWords(s2);

        // Collect words with count of 1
        vector<string> res;
        for (auto& it : count) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

