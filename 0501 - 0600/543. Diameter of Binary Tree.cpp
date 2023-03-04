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
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;

        int Lheight = height(root -> left, diameter);
        int Rheight = height(root -> right, diameter);

        diameter = max(diameter, Lheight + Rheight);
        return max(Lheight, Rheight) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int Ldiameter = 0;
        height(root, Ldiameter);
        return Ldiameter;
    }
};
