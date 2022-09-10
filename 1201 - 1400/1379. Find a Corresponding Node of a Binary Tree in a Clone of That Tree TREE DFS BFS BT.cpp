//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL || original == target)
            return cloned;        
        
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        // auto left = getTargetCopy(original->left, cloned->left, target);
        return left ? left : getTargetCopy(original->right, cloned->right, target);
    }
};
