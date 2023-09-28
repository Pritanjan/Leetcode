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



// A 2


