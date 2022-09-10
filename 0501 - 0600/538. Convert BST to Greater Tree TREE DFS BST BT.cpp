// https://leetcode.com/problems/convert-bst-to-greater-tree/
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
	
	// Reverse inorder traversal. Calculate sum and update nodes at the same traversal
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        convertBST(root -> right);
            sum += root -> val;
            root ->val = sum;
        
        convertBST(root -> left);
            return root;
    }
};
