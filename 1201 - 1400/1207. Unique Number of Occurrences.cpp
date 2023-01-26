class Solution {
public:  
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for (int i=0; i<arr.size(); i++)
            mp[arr[i]]++;
        
        set<int> unq;
        for(auto [first, second] : mp){
            unq.insert(second);
        }
            
        return unq.size() == mp.size();
    }
};





