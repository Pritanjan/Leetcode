//https://leetcode.com/problems/prefix-and-suffix-search/

class WordFilter {
public:
    unordered_map <string, int> ump;
    
    WordFilter(vector<string>& words) 
    {
        for(int i=0; i<words.size(); i++)
        {
            string s = words[i];
            for(int j=1; j<=s.size(); j++)
            {
                string s1 = s.substr(0,j);
                for(int k=0; k<s.size(); k++)
                {
                    string str = s.substr(k,s.size());
                    ump[s1 + "|" + str] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "|" +suffix;
        return ump[s] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
