// A 1 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;

        // Relax edges k + 1 times
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist;
            for(auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if (dist[u] != numeric_limits<int>::max() &&
                    dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        // Return the distance to destination if reachable, otherwise return -1
        return dist[dst] != numeric_limits<int>::max() ? dist[dst] : -1;
    }
};





// A 2 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>{});
        for (auto x : flights) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int stops = front.first;
            int cost = front.second.second;
            int node = front.second.first;
            if (stops > k) continue;
            
            for (auto it : adj[node]) {
                if (cost + it.second < dist[it.first] && stops <= k) {
                    dist[it.first] = cost + it.second;
                    q.push({stops + 1, {it.first, dist[it.first]}});
                }
            }
        }

        if (dist[dst] != 1e9) return dist[dst];
        return -1;
    }
};

