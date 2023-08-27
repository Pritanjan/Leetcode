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

