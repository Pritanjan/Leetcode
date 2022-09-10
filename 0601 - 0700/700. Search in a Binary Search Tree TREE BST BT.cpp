// https://leetcode.com/problems/search-in-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct TreeNode* searchBST(TreeNode* root, int val) {
        
        // if node is empty return NULL
        if(root == NULL)
            return NULL ;
        // if we find the node that we are looking for the return directly
        else if(root->val == val)
            return root;
        
        else if(root -> val < val)
            return searchBST(root->right, val);
        // if the val is smaller then the val of current node, then look for left child of the current node, else  look for right chind of the current node.
        else
            return searchBST(root->left, val );
        
    }
};
