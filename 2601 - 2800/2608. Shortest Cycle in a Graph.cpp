
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            vector<int> dist(n, (int)(1e9));
            vector<int> par(n, -1);

            dist[i] = 0;
            queue<int> que;
            que.push(i);

            while(!que.empty()) {
                int x = que.front();
                que.pop();
                
                for(int child : graph[x]){
                    if(dist[child] == (int)(1e9)) {
                        dist[child] = 1 + dist[x];
                        par[child] = x;

                        que.push(child);
                    }

                    else if(par[x] != child and par[child] != x)
                        ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};




