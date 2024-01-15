// A 1 

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> mp;
        
        for(vector<int> &m : matches){
            int win = m[0];
            int los = m[1];
            
            if(!mp.count(win)) mp[win] = 0;
            mp[los]++;
        }        
        for (auto& [player, nLosses] : mp){
            if (nLosses < 2){
                ans[nLosses].push_back(player);
            }                
        }
        return ans;
    }
};

// Time: O(nlogn)
// Space: O(n)






// A 2 

