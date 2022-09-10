//https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return NULL;
        
        if(root -> left && !root->left->left && !root->left->right)
            sum += root -> left -> val;
        if(root -> left )
            sum += sumOfLeftLeaves(root -> left);
        if(root -> right)
            sum += sumOfLeftLeaves(root -> right);
        
        return sum;
    }
};
