// A 1

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for(auto& path : paths) {
            mp[path[0]] = path[1];
        }

        string des = paths[0][0];
        while(mp.find(des) != mp.end()) {
            des = mp[des];
        }
        return des;
    }
};


// OR


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> inDegree, outDegree;
        for(auto& path : paths) {
            outDegree[path[0]]++;
            inDegree[path[1]]++;
        }

        for(auto& path : paths) {
            if(inDegree[path[1]] == 1 && outDegree[path[1]] == 0) {
                return path[1];
            }
        }
        return ""; 
    }
};






// A 2

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(int i=0; i<paths.size(); i++) {
            st.insert(paths[i][0]);
        }
        
        for(int i=0; i<paths.size(); i++) {
            string des = paths[i][1];
            if(st.find(des) == st.end()) {
                return des;
            }
        }        
        return "";
    }
};






// A 3


