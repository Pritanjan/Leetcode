// A 1

class Solution {
private: 
    void dfs(int node, vector<int> adj_ls[], int vis[]) {
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
        
        int* vis = new int[V]; // dynamic array
        for(int i=0; i<V; i++) {
            vis[i] = 0; // initialize the array
        }
        
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
