class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1, v2;
        map<char, int> mp1, mp2;
        
        for(auto i : word1){
            mp1[i]++;
        }
        for(auto i : word2){
            mp2[i]++;
        }
        
        for(auto i : mp1){
            v1.push_back(i.second);
        }
        
        for(auto i : mp2){
            v2.push_back(i.second);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int j = 0;
        for(auto i : mp2){
            if(mp1[i.first] == 0)
                j = 1;
        }
        if(j == 1)
            return false;
        
        return v1 == v2;
    }
};





