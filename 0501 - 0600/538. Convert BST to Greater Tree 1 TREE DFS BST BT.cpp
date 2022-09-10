// https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/

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
    void calsum(TreeNode* root, int &sum){
        if(!root)
            return ;
        calsum(root->left, sum);
            sum += root->val;
        calsum(root->right, sum);
    }
    
   void put(TreeNode* root, int &sum){
        if(!root)
            return ;
        put(root->left, sum);
            sum -= root->val;
            root->val += sum;
        put(root->right, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        calsum(root, sum);
        put(root, sum);
        
        return root;
    }
};
