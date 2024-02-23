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

