class Solution {
public:  
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        // Count the occurrences of each value in the array
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;

        // set<int> st;
        // n=0;
        // for(auto &m : mp){
        //     n++;
        //     st.insert(m.second);
        // }
        // return n == st.size();
        
        set<int> unq;
        for(auto [first, second] : mp){
            unq.insert(second);
        }            
        return unq.size() == mp.size();
    }
};





