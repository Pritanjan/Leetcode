// APPROACH 1

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == root2) return true;

        if(root1 == NULL or root2 == NULL or root1 -> val != root2 -> val) return 0;

        return flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right) or flipEquiv(root1 -> left, root2 -> right) && flipEquiv(root1 -> right, root2 -> left);
    }
};



// APPROACH 2
