// A 0 - Brute Force

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i=0; i<paths.size(); i++) {
            string candidate = paths[i][1];
            bool good = true;
            for(int j=0; j<paths.size(); j++) {
                if(paths[j][0] == candidate) {
                    good = false;
                    break;
                }
            }
            if(good) return candidate;
        }        
        return "";
    }
};






// A 1 - Using Hash Map

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


// OR


class Solution {
public:
    string dfs(const string& city, const unordered_map<string, string>& graph) {
        if(graph.find(city) == graph.end()) {
            return city;
        }
        return dfs(graph.at(city), graph);
    }

    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> graph;
        for(auto& path : paths) {
            string& cityA = path[0];
            string& cityB = path[1];
            graph[cityA] = cityB;
        }
        string& startCity = paths[0][0];

        return dfs(startCity, graph);
    }
};






// A 2 Hash Set

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


