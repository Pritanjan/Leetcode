//https://leetcode.com/problems/group-anagrams/

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
