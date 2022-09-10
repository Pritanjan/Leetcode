//https://leetcode.com/problems/invert-binary-tree/
//RECUSIVE DFS

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        TreeNode* tempRight = root->right;
            
        root->right = invertTree(root->left) ;
        root->left  = invertTree(tempRight);
        
        return root;
    }
};
