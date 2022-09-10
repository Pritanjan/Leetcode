// https://leetcode.com/problems/path-sum/
// COMPANY TAG FB

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val;
        else
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val) ;
    }
};

//Time complexity is O(n) and space complexity is O(log n)
