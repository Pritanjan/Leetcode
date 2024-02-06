// A 1 
// Sorting each string and using a hash table to group anagrams.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(string s : strs ){
            string s1 = s;
            sort(s1.begin(), s1.end());
            ump[s1].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto& i : ump){
            ans.push_back(i.second);
        }
        return ans;
    }
};






// A 2 
// Using a character count array to represent each string and grouping based on counts.

class Solution {
public:
    string cntChars(const string& str) {
        string cnts(26, 0);
        for(char ch : str) {
            cnts[ch - 'a']++;
        }
        return cnts;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(string& str : strs) {
            ump[cntChars(str)].push_back(str);
        }

        vector<vector<string>> res;
        for(auto& it : ump) {
            res.push_back(it.second);
        }
        return res;
    }
};






// A 3

