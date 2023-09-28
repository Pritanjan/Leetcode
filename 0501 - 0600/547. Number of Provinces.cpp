// A 1 - DFS
// It uses Adjency List
// Dynamic Memory Alloscation (vector for adjacency list and visited array)
// T.C. --> O(V^2) (Converting matrix to list) + O(V + E) (DFS traversal)
// S.C. --> O(V^2) (Adjacency List) + O(V) (Visited array)

class Solution {
private: 
    // void dfs(int node, vector<int> adj_ls[], int vis[]) {
    void dfs(int node, vector<int> adj_ls[], vector<int> &vis) {
        vis[node] = 1;
        for(auto it : adj_ls[node]) {
            if(!vis[it]) {
                dfs(it, adj_ls, vis);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& adj) {
        // to convert adjacency matrix into adjacency list
        int V = adj.size();
        vector<int> adj_ls[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adj_ls[i].push_back(j);
                    adj_ls[j].push_back(i);
                }
            }
        }
        
        // int* vis = new int[V]; // dynamic array
        // for(int i=0; i<V; i++) {
        //     vis[i] = 0; // initialize the array
        // }
        
        vector<int> vis(V, 0);
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj_ls, vis);
            }
        }
        
        // delete[] vis; // free the memory
        return cnt;
    }
};


// OR
// Graph Representation	- Adjacency Matrix
// Static Memory Allocation (visited array)
// T.C. --> O(V^2) (Visiting all edges)
// S.C. --> O(V) (Visited array)	


class Solution {
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &vis){
        vis[node] = 1;
        for(auto i=0; i<isConnected.size(); i++) {
            if(!vis[i] && isConnected[node][i]) 
                dfs(i, isConnected, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> vis(V, 0);
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};






// A 2 - BFS 

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> vis(V, 0);
        int cnt = 0;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                queue<int> que;
                que.push(i);
                while(!que.empty()) {
                    int node = que.front(); que.pop();
                    
                    vis[node] = true;
                    for(int j=0; j<V; j++) {
                        if(!vis[j] && isConnected[node][j] == 1) {
                            que.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};






// A 3 - Topological Sort

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> vis(V, 0);
        int cnt = 0;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                stack<int> stk;
                stk.push(i);
                while(!stk.empty()) {
                    int node = stk.top(); stk.pop();
                    
                    vis[node] = true;
                    for(int j=0; j<V; j++) {
                        if(!vis[j] && isConnected[node][j] == 1) {
                            stk.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};






// A 4

class Solution {
public:
    vector<int> parent;
    int find(int x) {        
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        // vector<int> parent(V);
        parent.resize(V); // Initialize the parent vector with the correct size
        for(int i=0; i<V; i++) {
            parent[i] = i;
        }

        // function<int(int)> find = [&](int x) {
        //     if(parent[x] == x) return x;
        //     return parent[x] = find(parent[x]);
        // };

        for(int i=0; i<V; i++) {
            for(int j=i+1; j<V; j++) {
                if(isConnected[i][j] == 1) {
                    if(find(i) != find(j)) {
                        parent[find(i)] = find(j);
                    }
                }
            }
        }

        set<int> st;
        for(int i=0; i<V; i++) {
            st.insert(find(i));
        }
        return st.size();        
    }
};






// A  5

