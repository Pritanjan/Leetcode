// A 1

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<int> md(n, 10000000);
        while (++connected < n) {
            md[i] = INT_MAX;
            int mj = i;
            for (int j = 0; j < n; ++j)
                if (md[j] != INT_MAX) {
                    md[j] = min(md[j], abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]));
                    mj = md[j] < md[mj] ? j : mj;
                }
            res += md[mj];
            i = mj;
        }
        return res;
    }
};





// A 2 - Kruskal's algorithm with Union-Find 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        // Calculate Manhattan distance between all pairs of points
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }

        // Sort edges by distance in ascending order
        sort(edges.begin(), edges.end());

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // Initialize parent array

        int totalCost = 0;
        for(auto& edge : edges) {
            int dist = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU != rootV) {
                parent[rootU] = rootV;
                totalCost += dist;
            }
        }
        return totalCost;
    }

private:
    int find(vector<int>& parent, int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent, parent[x]);
    }
};






// A 3 -  Prim's algorithm
// It is based on building the minimum spanning tree of the graph formed by the points and
// their Manhattan distances:

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2) return 0; // Handle empty or single-point case

        vector<int> parent(n);
        vector<int> minDist(n, INT_MAX);
        vector<bool> inTree(n, false);

        // Start with the first point as the initial node
        int currNode = 0;
        int totalCost = 0;
        for(int i=1; i<n; ++i) {
            inTree[currNode] = true;

            // Update minimum distances to neighboring points
            for(int j=0; j<n; ++j) {
                if(!inTree[j]) {
                    int dist = abs(points[currNode][0] - points[j][0]) +
                               abs(points[currNode][1] - points[j][1]);
                    if(dist < minDist[j]) {
                        minDist[j] = dist;
                        parent[j] = currNode;
                    }
                }
            }

            // Find the next node to add to the tree (smallest minDist)
            int minDistance = INT_MAX;
            for(int j=0; j<n; ++j) {
                if(!inTree[j] && minDist[j] < minDistance) {
                    minDistance = minDist[j];
                    currNode = j;
                }
            }
            totalCost += minDistance;
        }
        return totalCost;
    }
};


