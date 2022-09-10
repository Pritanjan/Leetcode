//https://leetcode.com/problems/maximum-depth-of-binary-tree/
// COMPANY TAG FB BLOOMBERG LINKEDIN

// APPROACH DFS
class Solution {
public:
    int depth(TreeNode* node){
        // IF NODE IS NULL THEN DEPTH IS 0
        if(!node)
            return NULL;
        
        int LD = depth(node->left) ;    // RETURNS LENGTH OF LEFT NODE
        int RD = depth(node->right);    // RETURNS LENGTH OF RIGHT NODE
        
        return 1+ max(LD, RD);          // 1 IS ADDED FOR ROOT NODE 
    }
    
    int maxDepth(TreeNode* root) {
        // if(!root)
        //     return 0;
        // else
            return depth(root);
    }
};

//Same 2nd way
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if(!root)
//            return NULL;
//        return 1 + max(maxDepth(root->left), maxDepth(root->right));
//    }
//};
