// A 1

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode* L = lowestCommonAncestor(root -> left,  p, q);
        TreeNode* R = lowestCommonAncestor(root -> right, p, q);        
        if(L && R) return root; // LCA found       
        return L ? L : R;
    }
};

// T.C. --> O(N)
// S.C. --> O(h)






// A 2 -  Using Path Tracing with Vectors:
// In this approach, we can trace the paths from the root to the two target nodes and
// then find the point where the paths diverge.

class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(!root) return false;       
        path.push_back(root);
        if(root == target) return true;       
        
        if((root -> left && findPath(root -> left,  target, path)) ||
          (root -> right && findPath(root -> right, target, path))) return true;
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;        
        if(!findPath(root, p, pathP) || !findPath(root, q, pathQ)) return nullptr;
                
        TreeNode* lca = nullptr;
        for(int i=0; i<min(pathP.size(), pathQ.size()); ++i) {
            if(pathP[i] == pathQ[i]) lca = pathP[i];
            else break;
        }        
        return lca;
    }
};






// A 3 - Using Iterative Approach with Parent Map:
// Use a parent map to store the parent of each node and then uses a set to keep track of 
// ancestors of one of the nodes while traversing from the other node towards the 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!parent.count(p) || !parent.count(q)) {
            TreeNode* node = st.top();  st.pop();
            if(node-> left) {
                parent[node -> left] = node;
                st.push(node -> left);
            }
            if(node -> right) {
                parent[node -> right] = node;
                st.push(node -> right);
            }
        }
        set<TreeNode*> ancestorsP;
        while(p) {
            ancestorsP.insert(p);
            p = parent[p];
        }        
        while(!ancestorsP.count(q)) {
            q = parent[q];
        }        
        return q;
    }
};






// A 4 - Level-Order Traversal with a Queue:
// use a level-order traversal to build a parent map that tracks the parent node for each node in the tree.
// Then, trace back from both nodes (p and q) to find their common ancestor, which is the LCA.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
                
        queue<TreeNode*> que;
        que.push(root);
        unordered_map<TreeNode*, TreeNode*> mp;  // store the parent

        // Perform level-order traversal and store parent pointers
        while(!mp.count(p) || !mp.count(q)) {
            TreeNode* node = que.front();   que.pop();
            if(node -> left) {
                mp[node -> left] = node;
                que.push(node -> left);
            }            
            if(node -> right) {
                mp[node -> right] = node;
                que.push(node -> right);
            }
        }

        // Trace back from both nodes to find the LCA
        unordered_set<TreeNode*> ust;  // store the ancessestor
        
        while(p) {
            ust.insert(p);
            p = mp[p];
        }
        
        while(!ust.count(q)) {
            q = mp[q];
        }
        return q;
    }
};






// A 5

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> depth;
        
        dfs(root, nullptr, 0, parent, depth);
        
        // Ensure p is at least as deep as q
        if(depth[p] < depth[q]) swap(p, q);
                
        // Lift p to the same depth as q
        while(depth[p] > depth[q]) p = parent[p];
                
        // Move both nodes up the tree until their parent is the same
        while(p != q) {
            p = parent[p];
            q = parent[q];
        }
        return p;
    }
    
    void dfs(TreeNode* node, TreeNode* par, int d, unordered_map<TreeNode*, TreeNode*>& parent, unordered_map<TreeNode*, int>& depth) {
        if(!node) return;
        
        parent[node] = par;
        depth[node] = d;
        
        dfs(node -> left,  node, d+1, parent, depth);
        dfs(node -> right, node, d+1, parent, depth);
    }
};






// A 6

