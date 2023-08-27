// A 1

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root == p or root == q) return root;
        
        TreeNode* L = lowestCommonAncestor(root->left, p,q);
        TreeNode* R = lowestCommonAncestor(root->right,p,q);
        if(L != NULL and R != NULL) return root;
        else if(L == NULL and R != NULL) return R;
        else if(L != NULL and R == NULL) return L;
        else return L;
    }
};

// T.C. --> O(N)
// S.C. --> O(h)


// OR


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

// This approach uses a parent map to store the parent of each node and
// then uses a set to keep track of ancestors of one of the nodes 
// while traversing from the other node towards the 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!parent.count(p) || !parent.count(q)) {
            TreeNode* node = st.top();
            st.pop();
            
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
