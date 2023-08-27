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






// A 2

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






// A 3

