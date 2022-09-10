//https://leetcode.com/problems/search-in-a-binary-search-tree/submissions

//iterative solution

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // if the current node is not empty, and it is not what 
        // we are looking for, continue to search
        while(root != NULL && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};
