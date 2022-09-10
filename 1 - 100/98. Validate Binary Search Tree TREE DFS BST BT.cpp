//https://leetcode.com/problems/validate-binary-search-tree/
//fb MICROSOFT AMAZON BLOOMBERG

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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX){ 
        if(root == NULL)
            return true;
        if((root->val >= max) || (root->val <= min))
            return false;
        else
            return helper(root->left,min,root->val) &&  helper(root->right,root->val,max);
    }
};



