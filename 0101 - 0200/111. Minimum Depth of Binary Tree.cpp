// Approach 1: Top-down DFS

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};



// In this code, we first check if the root node is NULL, and if so, we return 0.
// If the root node has no left or right child, we return 1 since the depth is just 1.
// If the root node has only one child, we recurse on that child and add 1 to the result. 
// If the root node has two children, we take the minimum of the depths of the left and right
// subtrees and add 1 to the result. Finally, we create a new tree and test the code on it.

// T.C. --> O(N)
// S.C. --> O(h)
