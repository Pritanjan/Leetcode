//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p or root == q)
            return root;
        
        TreeNode* L = lowestCommonAncestor(root->left, p,q);
        TreeNode* R = lowestCommonAncestor(root->right,p,q);
        
        if(L != NULL and R != NULL)
            return root;
        else if(L == NULL and R != NULL)
            return R;
        else if(L != NULL and R == NULL)
            return L;
        else
            return L;
    }
};

