// A 1 

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val < 2)  return root-> val;
        if(root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        // if(root->val == 3)
        return evaluateTree(root->left) && evaluateTree(root->right);        
    }
};

// 1 T 
// 0 F 
// 2 OR 
// 3 AND






// A 2 

