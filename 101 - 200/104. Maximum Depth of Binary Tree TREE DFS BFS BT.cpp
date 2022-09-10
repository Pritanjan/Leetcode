//https://leetcode.com/problems/maximum-depth-of-binary-tree/
// COMPANY TAG FB BLOOMBERG LINKEDIN

// APPROACH RECURSION
class Solution {
public:
    int Mdepth = 0;
    int maxDepth(TreeNode* root, int depth = 1) {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right){
            if(depth > Mdepth)
                Mdepth = depth;
            
            return Mdepth;
        }
        maxDepth(root->left, depth+1);
        maxDepth(root->right,depth+1);
        
         return Mdepth;
    }
};
