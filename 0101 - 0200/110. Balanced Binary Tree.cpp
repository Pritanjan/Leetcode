class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return NULL;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        int LH = 0, RH = 0;

        if(root == NULL) return true;

        LH = height(root -> left);
        RH = height(root -> right);

        if(abs(LH - RH) > 1) return 0;

        // return true;    
        // this function only checks if the root node is balanced or not, 
        // but it does not check if its subtrees are balanced. 
      
        // To check if a tree is balanced, we need to recursively check if its left and
        // right subtrees are balanced as well.
        // So we need to call the isBalanced function recursively on the left and right subtrees
        // and return true only if both subtrees are balanced and the difference in height 
        // between them is less than or equal to 1.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};




