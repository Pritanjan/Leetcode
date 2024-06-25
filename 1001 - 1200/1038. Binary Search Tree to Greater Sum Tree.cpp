// A 1

class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        
        bstToGst(root -> right);
        sum += root->val;
        root -> val = sum;
        
        bstToGst(root->left);
        return root;
    }
};

