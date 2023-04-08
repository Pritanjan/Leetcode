// APPROACH 1 [ DFS ]

// In this implementation, we use an unordered map visited to keep track of nodes that have already been cloned.
// If a node has already been cloned, we simply return the cloned node from the map. 
// Otherwise, we create a new Node with the same value as the original node and add it to the visited map. 
// We then iterate through the original node's neighbors vector and recursively clone each neighbor, 
// adding the cloned neighbor to the cloned node's neighbors vector.


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.count(node)) return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned ;
        
        for (auto neighbor : node->neighbors) {
            cloned->neighbors.push_back(dfs(neighbor, visited));
        }
        
        return cloned;
    }
};


// Time Complexity: O(N + M), where N is the number of nodes in the input graph, and
// M is the total number of edges in the input graph.
// We need to visit each node and each edge once during the DFS traversal.

// Space Complexity: O(N), where N is the number of nodes in the input graph.
// We need to maintain a map of visited nodes, and a recursive call stack for the DFS traversal.
// The maximum depth of the recursive call stack would be the number of nodes at the maximum depth 
// of the DFS traversal, which is O(N) in the worst case. 
// Therefore, the overall space complexity is O(N).








// APPROACH 2 [ BFS ]

// This implementation uses a queue to traverse the original graph in a breadth-first order. 
// For each node in the queue, we iterate through its neighbors and clone them if they have not
// been visited yet. We then add the cloned neighbors to the corresponding cloned node's neighbors vector
// The visited map is used to keep track of nodes that have already been cloned.
// The algorithm terminates when the queue is empty, and returns the cloned node
// corresponding to the original input node.


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (auto neighbor : curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        
        return visited[node];
    }
};


// Time Complexity: O(N + M), where N is the number of nodes in the input graph, 
// and M is the total number of edges in the input graph.
// We need to visit each node and each edge once during the BFS traversal.

// Space Complexity: O(N), where N is the number of nodes in the input graph.
// We need to maintain a map of visited nodes, and a queue for the BFS traversal. 
// The maximum size of the queue would be the number of nodes at the maximum depth
// of the BFS traversal, which is O(N) in the worst case.
// Therefore, the overall space complexity is O(N).





